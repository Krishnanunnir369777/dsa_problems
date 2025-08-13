#include <iostream>
#include <bits/stdc++.h>
using namespace std;



//memoization
class Solution {
public:
    int func(int idx1,int idx2,string& s,string& t,vector<vector<int>>& dp){
        if(idx1<0 || idx2<0){
            return 0;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(s[idx1]==t[idx2]){
            return dp[idx1][idx2]=1+func(idx1-1,idx2-1,s,t,dp);
        }
        else{
            return dp[idx1][idx2]=max(func(idx1-1,idx2,s,t,dp),func(idx1,idx2-1,s,t,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(n-1,n-1,s,t,dp);
    }
};






//tabulation


class Solution {
public:  //Time Complexity: O(N*N)
    
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=n;idx2++){
                if(s[idx1-1]==t[idx2-1]){
                    dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                }
                else{
                    dp[idx1][idx2]=max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
                }
            }
        }
        return dp[n][n];
    }
};











//optimised


class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string t=s;
        reverse(s.begin(),s.end());
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=n;idx2++){
                if(s[idx1-1]==t[idx2-1]){
                    curr[idx2]=1+prev[idx2-1];
                }
                else{
                    curr[idx2]=max(prev[idx2],curr[idx2-1]);
                }
            }
            prev=curr;

        }
        return prev[n];
    }
};