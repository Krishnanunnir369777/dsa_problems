 bool isPeakEle(vector<vector<int>>& mat,int row,int col){
        int n=mat.size();
        int m=mat[0].size();
        int del[][2]={{-1,0},{0,-1},{1,0},{0,1}};
        for(int i=0;i<4;i++){
            int new_r=row+del[i][0];
                int new_c=col+del[i][1];
                if(new_r>=0 && new_c>=0 && new_r<n && new_c<m && mat[new_r][new_c]>mat[row][col]){
                    return false;
            }
        }
        return true;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isPeakEle(mat,i,j)){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
        
    }








    