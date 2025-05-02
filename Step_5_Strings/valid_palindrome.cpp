#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool func1(string s) {
    string ans="";
    int n=s.length();
    for(char ch:s){
        if(isalnum(ch)){
            ans+=tolower(ch);
        }
    }
    int i=0,j=ans.length()-1;
    while(i<j){
        if(ans[i]!=ans[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool func2(string s) {
    int start=0;
    int end=s.size()-1;
    while(start<=end){
        if(!isalnum(s[start])){start++; continue;}
        if(!isalnum(s[end])){end--;continue;}
        if(tolower(s[start])!=tolower(s[end]))return false;
        else{
           start++;
           end--;
        }
    }
    return true;
}

int main(){
    string s="A man, a plan, a canal: Panama";
    cout<<func1(s);

}