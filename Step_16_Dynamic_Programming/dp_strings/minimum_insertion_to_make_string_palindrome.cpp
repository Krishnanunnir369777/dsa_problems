

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
            return 1+func(idx1-1,idx2-1,s,t,dp);
        }
        else{
            return dp[idx1][idx2]=max(func(idx1-1,idx2,s,t,dp),func(idx1,idx2-1,s,t,dp));
        }

    }
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        string t=s;
        reverse(s.begin(),s.end());
        int k=func(n-1,n-1,s,t,dp);


        return n-k;
    }
};








//tabulation



class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        string t=s;
        reverse(s.begin(),s.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int k=dp[n][n];


        return n-k;
    }
};





//optimised 



class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();
        string t=s;
        reverse(s.begin(),s.end());
        vector<int> prev(n+1,0),curr(n+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=1+prev[j-1];
                }
                else{
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        int k=curr[n];


        return n-k;
    }
};