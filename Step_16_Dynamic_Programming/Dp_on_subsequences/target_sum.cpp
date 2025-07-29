//memoization


class Solution {
public:
    int func(int idx,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(idx==0){
            if(nums[0]==0 && target==0){
                return 2;
            }
            if(target==0 || target==nums[idx]){
                return 1;
            }
            return 0;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int not_take=func(idx-1,target,nums,dp);
        int take=0;
        if(nums[idx]<=target){
            take=func(idx-1,target-nums[idx],nums,dp);
        }

        return dp[idx][target]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum-target<0){
            return 0;
        }
        int s2=(sum-target)/2;
        if((sum-target)%2==1){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(s2+1,-1));
        return func(n-1,s2,nums,dp);
    }
};




//tabulation

class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum-target<0){
            return 0;
        }
        int s2=(sum-target)/2;
        if((sum-target)%2==1){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(s2+1,0));
        if(nums[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
        if(nums[0]!=0 && nums[0]<=s2){
            dp[0][nums[0]]=1;
        }
        for(int idx=1;idx<n;idx++){
            for(int j=0;j<=s2;j++){
                int not_pick=dp[idx-1][j];
                int pick=0;
                if(nums[idx]<=j){
                    pick=dp[idx-1][j-nums[idx]];
                }
                dp[idx][j]=pick+not_pick;
            }
        }
        return dp[n-1][s2];
        
    }
};







//optimised
class Solution {
public:
    const int mod = (int)1e9 + 7;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum-target<0){
            return 0;
        }
        int s2=(sum-target)/2;
        if((sum-target)%2==1){
            return 0;
        }
        vector<int> prev(s2+1,0);
        if(nums[0]==0){
            prev[0]=2;
        }
        else{
            prev[0]=1;
        }
        if(nums[0]!=0 && nums[0]<=s2){
            prev[nums[0]]=1;
        }
        for(int idx=1;idx<n;idx++){
            vector<int> temp(s2+1,0);
            for(int j=0;j<=s2;j++){
                int not_take=prev[j];
                int take=0;
                if(nums[idx]<=j){
                    take=prev[j-nums[idx]];
                }
                temp[j]=(not_take+take)%mod;
            }
            prev=temp;
        }
        return prev[s2];
        
        
    }
};