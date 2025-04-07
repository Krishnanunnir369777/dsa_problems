#include <bits/stdc++.h>
using namespace std;




vector<int> func(vector<int>& asteroids) {
    stack<int> st;

    for (int ast : asteroids) {
        bool destroyed = false;

        while (!st.empty() && ast < 0 && st.top() > 0) {
            if (abs(st.top()) < abs(ast)) {
                st.pop(); // top asteroid explodes
                continue;
            } else if (abs(st.top()) == abs(ast)) {
                st.pop(); // both explode
            }
            destroyed = true; // current asteroid is destroyed
            break;
        }

        if (!destroyed) {
            st.push(ast);
        }
    }

    vector<int> result(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        result[i] = st.top();
        st.pop();
    }

    return result;
}

int main(){

    vector<int> arr={5,10,-5};
    vector<int> ans=func(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }

}