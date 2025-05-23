#include <bits/stdc++.h>
using namespace std;

string func(string& s){

    stack<string> st;

    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if((ch<=9 && ch>=0) || (ch>='A' && ch<='Z') || (ch>='a' && ch<='z')){
            string op(1,ch);
            st.push(op);
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            st.push("("+op2+ch+op1+")");

        }
    }
    return st.top();

}

int main(){
    string s="ab*c+";
    cout<<func(s);
}