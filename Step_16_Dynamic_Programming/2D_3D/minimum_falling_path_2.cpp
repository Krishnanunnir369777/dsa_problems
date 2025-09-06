

//memoization


class Solution {
public:
    int func(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n=grid.size();
        if(j<0 || j>=n){
            return 1e9;
        }
        if(i==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 1e9;
        // Try all other columns in next row
        for (int col = 0; col < n; col++) {
            if (col != j) {
                ans = min(ans, func(i + 1, col, grid, dp) + grid[i][j]);
            }
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int mini=1e9;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            mini=min(mini,func(0,j,grid,dp));
        }
        return mini;
    }
};







//tabulation


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), res = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for(int j = 0; j < n; ++j) {
            dp[0][j] = grid[0][j];
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int temp = INT_MAX;

                for(int k = 0; k < n; ++k) {
                    if(k != j) {
                        temp = min(temp, grid[i][j] + dp[i - 1][k]);
                    }

                    dp[i][j] = temp;
                }
            }
        }

        for(int j = 0; j < n; ++j) {
            res = min(res, dp[n - 1][j]);
        }

        return res;
    }
};