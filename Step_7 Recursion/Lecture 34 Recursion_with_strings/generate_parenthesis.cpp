#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void solve(int open,int close,string s,vector<string>& ans){
    if(open==0 && close==0){
        ans.push_back(s);
        return ;
    }
    if(open==close){
        string s1=s;
        s1.push_back('(');
        solve(open-1,close,s1,ans);
    }
    else if(open ==0){
        string s1=s;
        s1.push_back(')');
        solve(open,close-1,s1,ans);
    }
    else{
        string s1=s;
        string s2=s;
        s1.push_back('(');
        s2.push_back(')');
        solve(open-1,close,s1,ans);
        solve(open,close-1,s2,ans);
    }
}
vector<string> func1(int n){
    vector<string> ans;
    string s="";
    int open=n;
    int close=n;
    solve(open,close,s,ans);

    return ans;

}
int main(){
    vector<string> ans=func1(3);

    for(auto i:ans){
        cout<<i<<endl;
    }

}