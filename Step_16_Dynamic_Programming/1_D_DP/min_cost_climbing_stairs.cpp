

//memoization
class Solution {
public:
    int func(int idx,vector<int>& cost,vector<int>& dp){
        int n=cost.size();
        if(idx==0 || idx==1){
            return cost[idx];
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int one_step=cost[idx]+func(idx-1,cost,dp);
        int two_step=cost[idx]+func(idx-2,cost,dp);

        return dp[idx]=min(one_step,two_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(func(n-1,cost,dp),func(n-2,cost,dp));
    }
};






//tabulation


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);

    }
};


