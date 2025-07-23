
//   recursion
class Solution {
public:
    void func(int idx,string& output,string& s,vector<string>& v){
        int l=s.length();
        if(idx==l){
            v.push_back(output);
            return ;
        }
        func(idx+1,output,s,v);
        output+=s[idx];
        func(idx+1,output,s,v);
        output.pop_back();

        return ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<string> v1;
        vector<string> v2;
        string temp="";
        func(0,temp,text1,v1);
        temp="";
        func(0,temp,text2,v2);
        int maxi=0;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                if(v1[i]==v2[j]){
                    maxi=max(maxi,(int)v1[i].length());
                }
            }
        }
        return maxi;
    }
};








//memoization
class Solution {
public:
    int dp[1001][1001]; // dp[i][j] stores LCS of text1[i:] and text2[j:]

    int lcs(string& text1, string& text2, int i, int j) {
        // Base case: if any string is fully traversed
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        // Check memo table
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, include this character
        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + lcs(text1, text2, i + 1, j + 1);
        } else {
            // Else, take the max between skipping one character from either string
            dp[i][j] = max(lcs(text1, text2, i + 1, j), lcs(text1, text2, i, j + 1));
        }

        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp)); // Initialize memo table with -1
        return lcs(text1, text2, 0, 0);
    }
};
