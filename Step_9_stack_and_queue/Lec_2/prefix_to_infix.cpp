#include <bits/stdc++.h>
using namespace std;


string func(string& s){   //Time Complexity: O(n)
    int n=s.size();
    stack<string> st;
    
    for(int i=n-1;i>=0;i--){
        char ch=s[i];
        if((ch>=0 && ch<=9) || (ch>='A' && ch<='Z') ||(ch>='a' && ch<='z')){
            st.push(string(1,ch));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            st.push("("+t1+ch+t2+")");
        }
    }
    return st.top();

}

int main(){
    string s="*-A/BC-/AKL";
    cout<<func(s);
}