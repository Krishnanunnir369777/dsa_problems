#include <bits/stdc++.h>
using namespace std;


int knapsackUtil(vector<int>& wt,vector<int>& val,int idx,int W,vector<vector<int>>& dp){
    if(idx==0){
        return (W/wt[0])*val[0];
    }
    if(dp[idx][W]!=-1){
        return dp[idx][W];
    }
    int not_take=knapsackUtil(wt,val,idx-1,W,dp);
    int take=INT_MIN;
    if(wt[idx]<=W){
        take=val[idx]+knapsackUtil(wt,val,idx,W-wt[idx],dp);
    }
    return dp[idx][W]=max(not_take,take);

}

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the maximum value
    return knapsackUtil(wt, val, n - 1, W, dp);
}

int main() {
    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Weight capacity of the knapsack
    int n = wt.size(); // Number of items
    
    // Call the function to calculate and output the maximum value the thief can steal
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;

    return 0; // Return 0 to indicate successful program execution
}
