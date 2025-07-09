class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int peri=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==1){
                    peri+=4;
                    if(row>0 && grid[row-1][col]==1){
                    peri-=2;
                    }
                    if(col>0 && grid[row][col-1]==1){
                    peri-=2;
                    }
                }
                
            }
        }
        return peri;
    }
};








class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int peri=0;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==1){
                    peri+=dfs(grid,r,c);
                }
            }
        }
        return peri;
    }
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]==0){
            return 1;
        }
        if(grid[r][c]==-1){
            return 0;
        }
        grid[r][c]=-1;

        return (dfs(grid,r+1,c)+dfs(grid,r-1,c)+dfs(grid,r,c+1)+dfs(grid,r,c-1));
    }
};