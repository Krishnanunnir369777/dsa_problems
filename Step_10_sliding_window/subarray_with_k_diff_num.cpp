#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int func1(vector<int>& nums, int k) {   //O(n^2)
    int n=nums.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        map<int,int>mpp;
        for(int j=i;j<n;j++){
            mpp[nums[j]]++;
            if(mpp.size()==k){
                cnt++;
            }
            if(mpp.size()>k){
                break;
            }
        }
    }
    return cnt;
    
}








class Solution {
public:
    int func(vector<int>& nums,int k){
        int n=nums.size();
        int l=0,r=0;
        int cnt=0;
        unordered_map<int,int> mpp;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return func(nums,k)-func(nums,k-1);
        
        
    }
};












int main(){
    vector<int>arr={1,2,1,2,3};
    int k=2;
    cout<<func1(arr,k);
}