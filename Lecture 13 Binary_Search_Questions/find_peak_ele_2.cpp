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






int findMaxIndex(vector<vector<int>>& mat,int n,int col){
    int max_val=-1;
    int max_idx=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>max_val){
            max_idx=i;
            max_val=mat[i][col];
        }
    }
    return max_idx;
   }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {  //O(n*log(m))
        int n=mat.size();
        int m=mat[0].size();
        int s=0;
        int e=m-1;
        while(s<=e){
            int mid=(s+e)/2;
            int max_row_idx=findMaxIndex(mat,n,mid);
            int left=mid-1>=0 ? mat[max_row_idx][mid-1] : -1;
            int right=mid+1<m ? mat[max_row_idx][mid+1] : -1;
            if(mat[max_row_idx][mid]>left && mat[max_row_idx][mid]>right){
                return {max_row_idx,mid};
            }
            else if(mat[max_row_idx][mid]<left){
                e=mid-1;
            }
            else{
                s=mid+1;
            }

        }
        return {-1,-1};
    }

    