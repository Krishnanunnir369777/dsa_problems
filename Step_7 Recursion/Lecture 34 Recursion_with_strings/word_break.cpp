#include <bits/stdc++.h>
using namespace std;


unordered_map<string, bool> memo;

bool solve(string s,unordered_set<string>& wordset){
    if(memo.find(s)!=memo.end()){
        return memo[s];
    }
    int n=s.length();
    if(s.empty()) return true;
    for(int i=1;i<=n;i++){
        string prefix=s.substr(0,i);
        if(wordset.find(prefix)!=wordset.end() && solve(s.substr(i),wordset)){
            return true;
        }
    }
    memo[s]=false;
    return false;
}
bool func(string s,vector<string>& d){

    unordered_set<string> wordset(d.begin(),d.end());
    memo.clear();
    
    return solve(s,wordset);
}


int main() {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    cout << (func(s, wordDict) ? "true" : "false") << endl;
    return 0;
}
