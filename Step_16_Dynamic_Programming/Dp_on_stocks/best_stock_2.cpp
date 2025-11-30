// recursion

class Solution {//time complexity O(2^n)
                // space O(n)
public:
    int func(int idx,int buy,int n,vector<int>& prices){
        if(idx==n){
            return 0;
        }
        long profit=0;
        if(buy){
            profit=max(-prices[idx]+func(idx+1,0,n,prices),0+func(idx+1,1,n,prices));
        }
        else{
            profit=max(prices[idx]+func(idx+1,1,n,prices),0+func(idx+1,0,n,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return func(0,1,n,prices);
    }
};






//memoization

class Solution {//Time Complexity: O(N*2)
                //Space Complexity: O(N*2) + O(N)
public:
    int func(int idx,int buy,int n,vector<int>& prices,vector<vector<long>>& dp){
        if(idx==n){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        long profit=0;
        if(buy){
            profit=max(-prices[idx]+func(idx+1,0,n,prices,dp),0+func(idx+1,1,n,prices,dp));
        }
        else{
            profit=max(prices[idx]+func(idx+1,1,n,prices,dp),0+func(idx+1,0,n,prices,dp));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return func(0,1,n,prices);
    }
};







//tabulation


class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<long>> dp(n+1,vector<long>(2,0));

        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                long profit=0;
                if(buy){
                    profit=max(-prices[idx]+dp[idx+1][0],0+dp[idx+1][1]);
                }
                else{
                    profit=max(prices[idx]+dp[idx+1][1],0+dp[idx+1][0]);
                }
                dp[idx][buy]=profit;
            }
        }
        return dp[0][1];
    }
};