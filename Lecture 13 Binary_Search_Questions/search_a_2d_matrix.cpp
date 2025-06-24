bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}



           



//Time Complexity: O(N + logM)
 bool binary_search(vector<int>& matrix,int target){
        int n=matrix.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(matrix[mid]==target){
                return true;
            }
            else if(matrix[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;

    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(target>=matrix[i][0] && target<=matrix[i][m-1]){
                return binary_search(matrix[i],target);
            }
        }
        return false;
    }








    

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=0;
        int e=n*m-1;
        while(s<=e){
            int mid=(s+e)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
        
    }