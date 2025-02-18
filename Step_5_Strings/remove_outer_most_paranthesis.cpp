#include<iostream>
using namespace std;
#include <bits/stdc++.h>

string func1(string s){
    int  n=s.length();
    int first=0;
    int last=0;
    int sum=0;
    string ans="";
    if(n==0 || n==1){
        return ans;
    }
    
    for(int i=0;i<n;i++){
        
        if(s[i]=='('){
            sum++;
            last++;
            
        }
        else if(s[i]==')'){
            sum--;
            last++;
            
        }
        if(sum==0){
            for(int j=first+1;j<last-1;j++){
                ans.push_back(s[j]);
            }
            first=last;
            
            
        }
        
    }
    return ans;

    
}

int main(){
    string s="(()())(())";
    string ans=func1(s);
    int n=ans.length();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
}