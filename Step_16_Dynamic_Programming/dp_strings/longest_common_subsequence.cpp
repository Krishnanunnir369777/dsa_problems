
//memoization


// Function to find the length of the Longest Common Subsequence (LCS)
int lcsUtil(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {               //Time Complexity: O(N*M)
    // Base case: If either string reaches the end, return 0
    if (ind1 < 0 || ind2 < 0)
        return 0;

    // If the result for this pair of indices is already calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // If the characters at the current indices match, increment the LCS length
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
    else
        // If the characters don't match, consider two options: moving either left or up in the strings
        return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1, ind2 - 1, dp), lcsUtil(s1, s2, ind1 - 1, ind2, dp));
}

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1)); // Create a DP table
    return lcsUtil(s1, s2, n - 1, m - 1, dp);
}












//tabulation

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {   //shifting of index
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<n2;j++){
            dp[0][j]=0;
        }
        for(int idx1=1;idx1<=n1;idx1++){
            for(int idx2=1;idx2<=n2;idx2++){
                if(text1[idx1-1]==text2[idx2-1]){
                    dp[idx1][idx2]=1+(dp[idx1-1][idx2-1]);
                }
                else{
                    dp[idx1][idx2]=max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};







//optimised




