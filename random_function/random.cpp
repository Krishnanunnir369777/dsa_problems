class Solution {
public:
    bool solve(int row,int col,int n,int m,int idx,string word,vector<vector<char>>& board){
        if(idx==word.length()){
            return true;
        }
        if(row==n || col==m || row<0 || col<0 || board[row][col]!=word[idx] || board[row][col]=='!'){
            return false;
        }
        char c=board[row][col];
        board[row][col]='!';

        bool top=solve(row-1,col,n,m,idx+1,word,board);
        bool bottom=solve(row+1,col,n,m,idx+1,word,board);
        bool right=solve(row,col+1,n,m,idx+1,word,board);
        bool left=solve(row,col-1,n,m,idx+1,word,board);

        board[row][col]=c;

        return top||bottom||right||left;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int index=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[index]){
                    if(solve(i,j,n,m,index,word,board)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};