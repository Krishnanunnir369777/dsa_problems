#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void solve(string digits,string phone_map[],string output,vector<string>& ans){
    if(digits.empty()){
        ans.push_back(output);
        return ;
    }
    else{
        string letters=phone_map[digits[0]-'2'];
        for(char letter :letters){
            solve(digits.substr(1),phone_map,output+letter,ans);
        }

    }


}
vector<string> func(string digits){
    vector<string> ans;
    if(digits.empty()){
        return ans;
    }
    string phone_map[]={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output="";
    solve(digits,phone_map,output,ans);
    return ans;

}
int main(){
    string digits="23";
    vector<string> ans=func(digits);
    for(auto i:ans){
        cout<<i<<endl;
    }
}