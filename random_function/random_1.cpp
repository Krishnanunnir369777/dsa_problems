#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    /* Function to find the length of 
    the Longest Common Substring (LCS) */
    int longestCommonSubstr(string str1, string str2) {
        int maxi=0;
        int n=str1.length(),m=str2.length();
        
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    curr[j]=1+prev[j-1];
                    maxi=max(maxi,curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        return maxi;
    }
};

int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";

    // Create an instance of Solution class
    Solution sol;
    
    // Print the result
    cout << "The Length of Longest Common Substring is " << sol.longestCommonSubstr(s1, s2) << endl;

    return 0;
}