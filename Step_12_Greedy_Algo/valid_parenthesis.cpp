#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool func1(string s,int ind,int cnt){   // time comp  O(3^n)
                                       // space comp  O(n)
        if(cnt<0){
            return false;
        }
        int n=s.length();
        if(ind==n){
            return (cnt==0);
        }
        if(s[ind]=='('){
            return func1(s,ind+1,cnt+1);
        }
        if(s[ind]==')'){
            return func1(s,ind+1,cnt-1);
        }
        return func1(s,ind+1,cnt+1)|| func1(s,ind+1,cnt-1) || func1(s,ind+1,cnt);
}
bool checkValidString(string s) {
        int ind=0,cnt=0;
        return func1(s,ind,cnt);
        
}

bool func2(string s) {  //O(n)
        int n=s.length();
        int mini=0,maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                mini=mini+1;
                maxi=maxi+1;
            }
            else if(s[i]==')'){
                mini=mini-1;
                maxi=maxi-1;
            }
            else{
                mini=mini-1;
                maxi=maxi+1;
            }
            if(mini<0){
                mini=0;
            }
            if(maxi<0) return false;
        }
        return (mini==0);
        
    }


int main(){
    string s= "(*)";
    cout<<func2(s);
}