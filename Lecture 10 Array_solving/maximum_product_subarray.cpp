class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int p=nums[i];
            for(int j=i+1;j<n;j++){
                ans=max(ans,p);
                p=p*nums[j];
            }
            ans=max(ans,p);
        }
        return ans;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {  //O(n)
        int ans=INT_MIN;
        int pre=1,suf=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(pre==0){
                pre=1;
            }
            if(suf==0){
                suf=1;
            }
            pre=pre*nums[i];
            suf=suf*nums[n-1-i];

            ans=max(ans,max(pre,suf));
        }

        return ans;
    }
};