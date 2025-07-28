class Solution {
public:
    int func(int idx,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(idx==0){
            if(amount%coins[idx]==0){
                return amount/coins[idx];
            }
            else{
                return 1e9;
            }
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        int not_take=func(idx-1,amount,coins,dp);
        int take=1e9;
        if(coins[idx]<=amount){
            take=1+func(idx,amount-coins[idx],coins,dp);
        }
        return dp[idx][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=func(n-1,amount,coins,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};



//tabulation


// Function to find the minimum number of elements needed to form the target sum
int minimumElements(vector<int>& arr, int T) {
    int n = arr.size();
    
    // Create a 2D DP (Dynamic Programming) table with n rows and T+1 columns
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));
    
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9; // Set it to a very large value if not possible
    }
    
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            // Calculate the minimum elements needed without taking the current element
            int notTake = dp[ind - 1][target];
            
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];
                
            // Store the minimum of 'notTake' and 'take' in the DP table
            dp[ind][target] = min(notTake, take);
        }
    }
    
    // The answer is in the bottom-right cell of the DP table
    int ans = dp[n - 1][T];
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    
    return ans; // Return the minimum number of elements needed
}






