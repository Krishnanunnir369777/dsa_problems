
//memoization   my code
class Solution {
public:
    int func(int idx,int buy,int n,int cooldown,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(idx==n){
            return 0;
        }
        if(dp[idx][buy][cooldown]!=-1){
            return dp[idx][buy][cooldown];
        }
        int profit=0;
        if(cooldown){
            profit=func(idx+1,1,n,0,prices,dp);
        }
        else if(buy){
            profit=max(-prices[idx]+func(idx+1,0,n,cooldown,prices,dp),0+func(idx+1,1,n,cooldown,prices,dp));
        }
        else{
            profit=max(prices[idx]+func(idx+1,1,n,1,prices,dp),func(idx+1,0,n,0,prices,dp));
        }
        return dp[idx][buy][cooldown]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int idx=0;
        int buy=1;
        int cooldown=0;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return func(idx,buy,n,cooldown,prices,dp);
    }
};



// better memoization  Time Complexity: O(N*2). Space Complexity: O(N*2) + O(N). 
class Solution {
public:
    int func(int idx,int buy,int n,vector<int>& prices,vector<vector<int>>& dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int profit=0;
        if(buy){
            profit=max(-prices[idx]+func(idx+1,0,n,prices,dp),0+func(idx+1,1,n,prices,dp));
        }
        else{
            profit=max(prices[idx]+func(idx+2,1,n,prices,dp),func(idx+1,0,n,prices,dp));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int idx=0;
        int buy=1;

        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(idx,buy,n,prices,dp);
    }
};





//tabulation  Time Complexity: O(N*2). Space Complexity: O(N*2). 

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));

        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[idx]+dp[idx+1][0],0+dp[idx+1][1]);
                }
                else{
                    profit=max(prices[idx]+dp[idx+2][1],dp[idx+1][0]);
                }
                dp[idx][buy]=profit;
            }
        }
        return dp[0][1];
    }
};



//space optimised Time Complexity: O(N). Space Complexity: O(1).


class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> front2(2,0);
        vector<int> front1(2,0);
        vector<int> curr(2,0);

        for(int idx=n-1;idx>=0;idx--){

            curr[1]=max(-prices[idx]+front1[0],0+front1[1]);
            curr[0]=max(prices[idx]+front2[1],front1[0]);

            front2=front1;
            front1=curr;
            
        }
        return curr[1];
    }
};