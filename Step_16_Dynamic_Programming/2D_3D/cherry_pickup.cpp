//memoization
class Solution {
public:
    int func(int row,int col1,int col2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        int n=grid.size();
        int m=grid[0].size();
        if(col1<0 || col1>=m || col2<0 || col2>=m){
            return -1e9;
        }
        if(row==n-1){
            if(col1==col2){
                return grid[row][col1];
            }
            else{
                return grid[row][col1]+grid[row][col2];
            }
        }
        if(dp[row][col1][col2]!=-1){
            return dp[row][col1][col2];
        }
        int maxi=INT_MIN;
        for(int j1=-1;j1<=1;j1++){
            for(int j2=-1;j2<=1;j2++){
                int ans;
                if(col1==col2){
                    ans=grid[row][col1]+func(row+1,col1+j1,col2+j2,grid,dp);
                }
                else{
                    ans=grid[row][col1]+grid[row][col2]+func(row+1,col1+j1,col2+j2,grid,dp);
                }
                maxi=max(ans,maxi);
            }
        }
        return dp[row][col1][col2]=maxi;

    }
    int cherryPickup(vector<vector<int>>& grid) {  //Time Complexity: O(N*M*M) * 9
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return func(0,0,m-1,grid,dp);
    }
};




