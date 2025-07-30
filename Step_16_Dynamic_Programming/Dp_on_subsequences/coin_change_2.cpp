class Solution {
public:
    int func(int idx,int target,vector<int>& coins){
        if(idx==0){
            return (target%coins[idx]==0);
        }
        int not_take=func(idx-1,target,coins);
        int take=0;
        if(coins[idx]<=target){
            take=func(idx,target-coins[idx],coins);
        }

        return not_take+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return func(n-1,amount,coins);
    }
};









//memoization




class Solution {
public:
    int func(int idx,int target,vector<int>& coins,vector<vector<int>>& dp){
        if(idx==0){
            return (target%coins[idx]==0);
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int not_take=func(idx-1,target,coins,dp);
        int take=0;
        if(coins[idx]<=target){
            take=func(idx,target-coins[idx],coins,dp);
        }

        return dp[idx][target]=not_take+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return func(n-1,amount,coins,dp);
    }
};






//tabulation
// Function to count the number of ways to make change for a given target sum
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, 0)); // Create a DP table

    // Initializing base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = 1;
        // Else condition is automatically fulfilled,
        // as dp array is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            long notTaken = dp[ind - 1][target];

            long taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind][target - arr[ind]];

            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][T];
}




//optimised


long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<long> prev(T + 1, 0);  // Create a vector to store the previous DP state

    // Initialize base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = 1;  // There is one way to make change for multiples of the first coin
        // Else condition is automatically fulfilled,
        // as the prev vector is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        vector<long> cur(T + 1, 0);  // Create a vector to store the current DP state
        for (int target = 0; target <= T; target++) {
            long notTaken = prev[target];  // Number of ways without taking the current coin

            long taken = 0;
            if (arr[ind] <= target)
                taken = cur[target - arr[ind]];  // Number of ways by taking the current coin
                
            cur[target] = notTaken + taken;  // Total number of ways for the current target
        }
        prev = cur;  // Update the previous DP state with the current state for the next coin
    }

    return prev[T];  // Return the total number of ways to make change for the target
}