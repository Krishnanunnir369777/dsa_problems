#include <bits/stdc++.h>
using namespace std;


//recursion
bool func(int idx,int k,vector<int>& arr){
    if(k==0){
        return true;
    }
    if(idx==0){
        return arr[idx]==k;
    }
    bool not_take=func(idx-1,k,arr);
    bool take=false;
    if(k>=arr[idx]){
        take=func(idx-1,k-arr[idx],arr);
    }
    return take || not_take;
}
bool subsetSumToK(int n,int k,vector<int>& arr){
    return func(n-1,k,arr);
}





//memoization
// Function to check if there is a subset of 'arr' with a sum equal to 'target'
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // If the target sum is 0, we have found a subset
    if (target == 0)
        return true;

    // If we have reached the first element in 'arr'
    if (ind == 0)
        return arr[0] == target;

    // If the result for this subproblem has already been computed, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Try not taking the current element into the subset
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    // Try taking the current element into the subset if it doesn't exceed the target
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the dp array to avoid recomputation
    return dp[ind][target] = notTaken || taken;
}

// Function to check if there is a subset of 'arr' with a sum equal to 'k'
bool subsetSumToK(int n, int k, vector<int>& arr) {
    // Initialize a 2D DP array for memoization
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    // Call the recursive subsetSumUtil function
    return subsetSumUtil(n - 1, k, arr, dp);
}











//tabulation

// Function to check if there is a subset of 'arr' with a sum equal to 'k'
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Initialize a 2D DP array with dimensions (n x k+1) to store subproblem results
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    // Fill the DP array iteratively
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = dp[ind - 1][target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            // Store the result in the DP array for the current subproblem
            dp[ind][target] = notTaken || taken;
        }
    }

    // The final result is stored in dp[n-1][k]
    return dp[n - 1][k];
}














