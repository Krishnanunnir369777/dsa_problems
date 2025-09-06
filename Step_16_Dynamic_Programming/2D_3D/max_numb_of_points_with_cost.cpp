

class Solution {
public:
   long long func(int r,int c,vector<vector<int>>& points,vector<vector<int>>& dp){
    int n=points.size();
    int m=points[0].size();
    if(r<0 || r>=n || c<0 || c>=m){
        return -1e9;
    }
    if(r==n-1){
        return points[r][c];
    }
    if(dp[r][c]!=-1){
        return dp[r][c];
    }
    long long ans = -1e9;
    for (int new_c = 0; new_c < m; new_c++) {
        ans = max(ans, points[r][c] + func(r+1, new_c, points,dp) - abs(c - new_c));
    }
    return dp[r][c]=ans;
   }
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        long long maxi=-1;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            maxi=max(maxi,func(0,j,points,dp));
        }
        return maxi;
        
    }
};











class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int m=points[0].size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
        for(int j=0;j<m;j++){
            dp[0][j]=points[0][j];
        }
        for(int i=1;i<n;i++){
            vector<long long> left(m),right(m);

            left[0]=dp[i-1][0];
            for(int j=1;j<m;j++){
                left[j]=max(left[j-1]-1,dp[i-1][j]);
            }
            right[m-1]=dp[i-1][m-1];
            for(int j=m-2;j>=0;j--){
                right[j]=max(right[j+1]-1,dp[i-1][j]);
            }
            for(int j=0;j<m;j++){
                dp[i][j]=points[i][j]+max(left[j],right[j]);
            }
        }
        long long ans=INT_MIN;
        for(int j=0;j<m;j++){
            ans=max(ans,dp[n-1][j]);
        }
        return ans;

    }
};