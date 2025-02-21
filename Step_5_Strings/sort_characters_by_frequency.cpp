#include <iostream>
using namespace std;
#include <bits/stdc++.h>

string func1(string s){

    unordered_map<char,int> mpp;

    for(char ch:s){
        mpp[ch]++;
    }
    vector<pair<int,char>> v;
    for(auto it:mpp){
        v.push_back({it.second,it.first});
    }
    sort(v.begin(),v.end());
    string ans="";
    for(int i=v.size();i>=0;i--){
        ans+=string(v[i].first,v[i].second);
    }
    return ans;

    
}

int main(){
    string s="tree";
    string ans=func1(s);
    for(char ch:ans){
        cout<<ch;
    }
}