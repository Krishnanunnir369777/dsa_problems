
//recursion
class Solution {
public:
    int func(int idx,int cap,int buy,int n,vector<int>& prices){
        if(idx==n || cap==0){
            return 0;
        }
        int profit=0;
        if(buy){
            profit=max(-prices[idx]+func(idx+1,cap,0,n,prices),0+func(idx+1,cap,1,n,prices));
        }
        else{
            profit=max(prices[idx]+func(idx+1,cap-1,1,n,prices),0+func(idx+1,cap,0,n,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int idx=0;
        int cap=2;
        int buy=1;
        int n=prices.size();
        return func(idx,cap,buy,n,prices);
    }
};




//memoization
class Solution {
public:
    int func(int idx,int cap,int buy,int n,vector<int>& prices,vector<vector<vector<int>>>& dp){//Time Complexity: O(N*2*3)
                                                                                               //
        if(idx==n || cap==0){
            return 0;
        }
        if(dp[idx][buy][cap]!=-1){
            return dp[idx][buy][cap];
        }
        int profit=0;
        if(buy){
            profit=max(-prices[idx]+func(idx+1,cap,0,n,prices,dp),0+func(idx+1,cap,1,n,prices,dp));
        }
        else{
            profit=max(prices[idx]+func(idx+1,cap-1,1,n,prices,dp),0+func(idx+1,cap,0,n,prices,dp));
        }
        return dp[idx][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int idx=0;
        int cap=2;
        int buy=1;
        int n=prices.size();
        vector<vector<vector<int>>>dp (n,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(idx,cap,buy,n,prices,dp);
    }
};






//tabulation
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<vector<int>>>dp (n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[idx]+dp[idx+1][0][cap],0+dp[idx+1][1][cap]);
                    }
                    else{
                        profit=max(prices[idx]+dp[idx+1][1][cap-1],0+dp[idx+1][0][cap]);
                    }
                    dp[idx][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};





//space optimised

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> ahead(2,vector<int>(3,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[idx]+ahead[0][cap],0+ahead[1][cap]);
                    }
                    else{
                        profit=max(prices[idx]+ahead[1][cap-1],0+ahead[0][cap]);
                    }
                    curr[buy][cap]=profit;
                }
                ahead=curr;
            }
        }
        return curr[1][2];
    }
};





