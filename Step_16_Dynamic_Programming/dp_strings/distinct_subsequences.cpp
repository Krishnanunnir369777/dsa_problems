//recurion



class Solution {
public:
    int func(int idx1,int idx2,string& s,string& t){
        if(idx2<0){
            return 1;
        }
        if(idx1<0){
            return 0;
        }
        if(s[idx1]==t[idx2]){
            return func(idx1-1,idx2-1,s,t)+func(idx1-1,idx2,s,t);
        }
        else{
            return func(idx1-1,idx2,s,t);
        }
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        return func(n-1,m-1,s,t);
    }
};


//memoization

class Solution {
public:
    int func(int idx1,int idx2,string& s,string& t,vector<vector<int>>& dp){
        if(idx2<0){
            return 1;
        }
        if(idx1<0){
            return 0;
        }
        if(idx1<idx2){
            return 0;
        }
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(s[idx1]==t[idx2]){
            return func(idx1-1,idx2-1,s,t,dp)+func(idx1-1,idx2,s,t,dp);
        }
        else{
            return func(idx1-1,idx2,s,t,dp);
        }
    }
    int numDistinct(string s, string t) {  //Time Complexity: O(N*M)
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s,t,dp);
    }
};






//tabulation



class Solution {
public:
    const int prime=1e9+7;
    int numDistinct(string s, string t) { //Time Complexity: O(N*M)
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%prime;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};





//space optimised


class Solution {
public:
    const int prime=1e9+7;
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<int> prev(m+1,0),curr(m+1,0);
        prev[0]=1;
        curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=(prev[j-1]+prev[j])%prime;
                }
                else{
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return curr[m];
    }
};