#include <bits/stdc++.h>
using namespace std;

string func(string num, int k) {
    stack<int> st;

    for(char digit:num){
        while(k>0 && !st.empty() && st.top()>digit){
            st.pop();
            k--;
        }
        st.push(digit);
    }
    while(k>0){
        st.pop();
        k--;
    }
    if(st.empty()){
        return "0";
    }
    string result;
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    while(result.size()!=0 && result.back()=='0'){
        result.pop_back();
    }
    if(result.size()==0){
        return "0";
    } 
    reverse(result.begin(),result.end());


    return result;
}


int main(){
    string num="1432219";
    int k=3;
    cout<<func(num,k);
}