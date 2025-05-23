#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int func1(vector<int>& nums, int k) {

    int n=nums.size();
    int ans=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i;j<n;j++){
            if(nums[j]%2!=0){
                cnt++;
            }
            if(cnt==k){
                ans++;
               
            }
        }
    }
    return ans;
}

int func2(vector<int>& nums,int k){   // similar to binary_sub_array_sum problem
    if(k<0) return 0;
    int n=nums.size();
    int r=0,l=0;
    int sum=0,cnt=0;
    while(r<n){
        sum+=nums[r]%2;
        while(sum>k){
            sum=sum-(nums[l]%2);
            l++;
        }
        cnt=cnt+(r-l+1);
        r++;
    }
    return cnt;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return func2(nums,k)-func2(nums,k-1);
    
}

int main(){
    vector<int> arr={1,1,2,1,1};
    int k=3;
    cout<<numberOfSubarrays(arr,k);
}