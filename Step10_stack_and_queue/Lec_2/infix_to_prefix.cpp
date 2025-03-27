#include <bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Convert infix expression to postfix notation
string convertInfixToPostfix(string s) {

    stack<char> st;
    string res;
    int sz = s.size();
 
    for (int i = 0; i < sz; i++) {
        char c=s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9')){
                res += c;
            }
            
         else if (s[i] == '(') {
            st.push(s[i]);
        }else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && prec(s[i]) <
            prec(st.top())) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    return res;
}

// Convert infix expression to prefix notation
string convertToPrefix(string infix) {

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    

    string postfix = convertInfixToPostfix(infix);

    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main(){
    string s="(a-b/c)*(a/k-l)";
    string ans=convertToPrefix(s);
    cout<<ans;

}