
//memoization
class Solution {
public: 
    int func(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid){
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int top=grid[i][j]+func(i-1,j,dp,grid);
        int left=grid[i][j]+func(i,j-1,dp,grid);

        return dp[i][j]=min(top,left);
    }
    int minPathSum(vector<vector<int>>& grid) {    //Time Complexity: O(N*M)
                                                  // Space Complexity: O((M-1)+(N-1)) + O(N*M)
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(n-1,m-1,dp,grid);
    }
};










//tabulation
class Solution {
public: 
    
    int minPathSum(vector<vector<int>>& grid) {//Time Complexity: O(N*M)   Space Complexity: O(N*M)
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }
                else{
                    int top=grid[i][j];
                    int left=grid[i][j];
                    if(i>0){
                        top+=dp[i-1][j];
                    }
                    else{
                        top+=1e9;
                    }
                    if(j>0){
                        left+=dp[i][j-1];
                    }
                    else{
                        left+=1e9;
                    }
                    dp[i][j]=min(left,top);
                }
            }
        }
        return dp[n-1][m-1];
        
    }
};






//space optimised

class Solution {
public: 
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> prev(m,0);
        for(int i=0;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    temp[j]=grid[i][j];
                    continue;
                }
                else{
                    int top=grid[i][j];
                    int left=grid[i][j];
                    if(i>0){
                        top+=prev[j];
                    }
                    else{
                        top+=1e9;
                    }
                    if(j>0){
                        left+=temp[j-1];
                    }
                    else{
                        left+=1e9;
                    }
                    temp[j]=min(left,top);
                }
            }
            prev=temp;
        }
        return prev[m-1];
        
    }
};