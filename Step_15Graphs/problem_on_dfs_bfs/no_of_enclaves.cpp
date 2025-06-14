class Solution {
public:
    void dfs(int row,int col,int delx[],int dely[],vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<4;i++){
            int nrow=row+delx[i];
            int ncol=col+dely[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,delx,dely,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delx[]={-1,0,1,0};
        int dely[]={0,1,0,-1};
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,delx,dely,vis,grid);
            }
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,delx,dely,vis,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,delx,dely,vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,delx,dely,vis,grid);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                    //dfs(i,j,delx,dely,vis,grid);
                }
            }
        }
        return cnt;
    }
};