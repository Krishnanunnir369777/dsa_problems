#include <iostream>
using namespace std;
#include <bits/stdc++.h>

string func(vector<string>& s){  //O(N log N * M + M)
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
//optimised  
string longestCommonPrefix(vector<string>& strs) {  //O(N*M)
        int n=strs.size();
        if(strs.empty()){
            return "";
        }
        string prefix=strs[0];
        for(int i=1;i<n;i++){
            int j=0;
            while(j<prefix.length() && j<strs[i].length() && prefix[j]==strs[i][j]){
                j++;
            }
            prefix=prefix.substr(0,j);
            if(prefix==""){
                return "";
            }
        }
        return prefix;



    }

int main(){
    vector<string> s={"krui","krua","kruc"};
    cout<<func(s);
}