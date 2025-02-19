#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool func1(string s1,string s2){
    if(s1.length()!=s2.length()){
        return false;
    }
    unordered_map<char,int> m1,m2;
    for(int i=0;i<s1.length();i++){
        if(m1.find(s1[i])==m1.end()){
            m1[s1[i]]=i;
        }
        if(m2.find(s2[i])==m2.end()){
            m2[s2[i]]=i;
        }
        if(m1[s1[i]]!=m2[s2[i]]){
            return false;
        }
    }
    return true;
}
int main(){

    string s1="egg";
    string s2="adh";
    cout<<func1(s1,s2);
}