#include <iostream>
#include <bits/stdc++.h>
using namespace std;



//tabulation
int lcs1(string& s1,string& s2){
    int n1=s1.length();
    int n2=s2.length();
    int ans=0;
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            
        }
    }
    return ans;
}




//space optimised

int lcs2(string& s1,string& s2){
    int n1=s1.length();
    int n2=s2.length();
    int ans=0;
    vector<int> prev(n2+1,0),curr(n2+1,0);
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]=1+prev[j-1];
                ans=max(ans,curr[j]);
            }
            else{
                curr[j]=0;
            }
        }
        prev=curr;
    }
    return ans;
}





int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";

    // Call the function to find and output the length of the Longest Common Substring
    cout << "The Length of Longest Common Substring is " << lcs2(s1, s2) << endl;

    return 0; // Return 0 to indicate successful program execution
}
