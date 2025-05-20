#include <windows.h> //sleep and system (termical color)
#include <iostream> //input and output
#include <string>
#include <algorithm> //sort method used
#include<fstream> //file handling
#include <regex> //email validation

using namespace std;



class Solution {
public:
    bool is_palindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int idx, string s,vector<string>& output,vector<vector<string>>& ans){
        if(idx==s.size()){
            ans.push_back(output);
            return ;
        }
        for(int i=idx;i<s.size();++i){
            if(is_palindrome(s,idx,i)){
                output.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,output,ans);
                output.pop_back();

            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        int idx=0;
        solve(idx,s,output,ans);

        return ans;   
    }
};
