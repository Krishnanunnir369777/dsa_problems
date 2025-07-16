//memoization
class Solution {
public:
    int func(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int n=triangle.size();
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==n-1){
            return triangle[i][j];
        }
        int down=triangle[i][j]+func(i+1,j,triangle,dp);
        int right=triangle[i][j]+func(i+1,j+1,triangle,dp);


        return dp[i][j]=min(down,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {//Time Complexity: O(N*N)
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return func(0,0,triangle,dp);

    }
};




//tabulation
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int diagonal=triangle[i][j]+dp[i+1][j+1];

                dp[i][j]=min(down,diagonal);
            }
        }
        return dp[0][0];

    }
};





//space optimised
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev(n,0);
        vector<int> curr(n,0);
        for(int j=0;j<n;j++){
            prev[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+prev[j];
                int diagonal=triangle[i][j]+prev[j+1];

                curr[j]=min(down,diagonal);
            }
            prev=curr;
        }
        return prev[0];

    }
};




