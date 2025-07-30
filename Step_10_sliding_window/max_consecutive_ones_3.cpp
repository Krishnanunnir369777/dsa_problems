#include <bits/stdc++.h>
using namespace std;


int func1(vector<int>& nums, int k) {   //O(n^2)
    int n=nums.size();
    
    int ans=0;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i;j<n;j++){
            if(nums[j]==0){
                count++;
            }
            if(count>k){
                break;
            }
            if(count<=k){
                ans=max(ans,j-i+1);
            }

        }
    }
    return ans;
    
}


int func2(vector<int>& nums, int k) {      //O(2N)
    int n=nums.size();
    int l=0,r=0;
    int cnt=0;
    int maxi=0;
    while(r<n){
        if(nums[r]==0){
            cnt++;
        }
        if(cnt>k){
            while(nums[l]==1 && l<r){
                l++;
            }
            l++;
            cnt--;

        }
        if(cnt<=k){
            maxi=max(r-l+1,maxi);
        }
        r++;
    }
    return maxi;
}

   //OPTIMISED
int func3(vector<int>& nums,int k){   //O(n)
    int n=nums.size();
    int r=0,l=0;
    int maxi=0,cnt=0;
    while(r<n){
        if(nums[r]==0){
            cnt++;
        }
        if(cnt>k){
            if(nums[l]==0){
                cnt--;
            }
            l++;
        }
        if(cnt<=k){
            maxi=max(maxi,r-l+1);
        }
        r++;
    }
    return maxi;
}

int main(){

    vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout<<func3(nums,k);

}