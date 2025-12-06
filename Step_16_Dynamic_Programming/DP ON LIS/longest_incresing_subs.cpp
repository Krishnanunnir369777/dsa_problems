class Solution {
public:
    int func(int idx,int n,int prev_idx,vector<int>& nums,vector<vector<int>>& dp){
        if(idx==n){
            return 0;
        }
        if(dp[idx][prev_idx+1]!=-1){
            return dp[idx][prev_idx+1];
        }
        //select
        int skip=func(idx+1,n,prev_idx,nums,dp);
        int include=0;
        if(prev_idx==-1){
            include=1+func(idx+1,n,idx,nums,dp);
        }
        else if(nums[idx]>nums[prev_idx]){
            include=1+func(idx+1,n,idx,nums,dp);
        }
        
        return dp[idx][prev_idx+1]=max(include,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int idx=0;
        int prev_idx=-1;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return func(idx,n,prev_idx,nums,dp);
    }
};








class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int> next(n+1,0),curr(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            for(int prev=idx-1;prev>=-1;prev--){
                int skip=0+next[prev+1];
                int pick=0;
                if(prev==-1 || nums[idx]>nums[prev]){
                    pick=1+next[idx+1];
                }
                curr[prev+1]=max(skip,pick);
            }
            next=curr;
        }
        return curr[0];
    }
};





class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                    
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};














