//memoization
class Solution {
public:
    bool func(int idx,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0){
            return true;
        }
        if(idx==0){
            return nums[idx]==target;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        bool unpick=func(idx-1,target,nums,dp);
        bool pick=false;
        if(target>=nums[idx]){
            pick=func(idx-1,target-nums[idx],nums,dp);
        }
        return dp[idx][target]=pick||unpick;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        else{
            int k=sum/2;
            vector<vector<int>> dp(n,vector<int>(k+1,-1));
            return func(n-1,k,nums,dp);
        }
    }
};




//tabulation
class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        else{
            int k=sum/2;
            vector<vector<bool>> dp(n,vector<bool>(k+1,false));
            for(int i=0;i<n;i++){
                dp[i][0]=true;
            }
            if(k>=nums[0]){
                dp[0][nums[0]]=true;
            }
            for(int idx=1;idx<n;idx++){
                for(int target=1;target<=k;target++){
                    bool unpick=dp[idx-1][target];
                    bool pick=false;
                    if(nums[idx]<=target){
                        pick=dp[idx-1][target-nums[idx]];
                    }
                    dp[idx][target]=pick|| unpick;
                }
            }

            return dp[n-1][k];

        }
    }
};












//optimised
class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        else{
            int k=sum/2;
            vector<bool> prev (k+1,false);
            prev[0]=true;
            if(k>=nums[0]){
                prev[nums[0]]=true;
            }
            for(int idx=1;idx<n;idx++){
                vector<bool> temp(k+1,false);
                for(int target=1;target<=k;target++){
                    bool unpick=prev[target];
                    bool pick=false;
                    if(nums[idx]<=target){
                        pick=prev[target-nums[idx]];
                    }
                    temp[target]=pick|| unpick;
                }
                prev=temp;
            }

            return prev[k];

        }
    }
};