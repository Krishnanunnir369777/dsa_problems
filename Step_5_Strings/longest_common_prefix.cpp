#include <iostream>
using namespace std;
#include <bits/stdc++.h>

string func(vector<string>& s){
    if(s.empty()){
        return "";
    }
    sort(s.begin(),s.end());
    string first=s[0],last=s.back(),result="";
    for(int i=0;i<first.length();i++){
        if(first[i]==last[i]){
            result+=first[i];
        }
    }
    return result;

}

int main(){
    vector<string> s={"krui","krua","kruc"};
    cout<<func(s);
}