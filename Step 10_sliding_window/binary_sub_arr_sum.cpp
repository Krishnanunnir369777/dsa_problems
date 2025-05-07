#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int func1(vector<int>& nums, int goal) {  //o(N^2)
    int cnt=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum==goal){
                cnt++;
            }
            if(sum>goal){
                break;
            }
        }
    }
    return cnt;   
}

int func2(vector<int>& nums, int goal) {  //O(n)
    int n=nums.size();
    int cnt=0;
    int sum=0;
    map<int,int> mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        int balance=sum-goal;
        cnt+=mpp[balance];
        mpp[sum]+=1;
    }
    return cnt;
    
}

int func3(vector<int>& nums,int goal){        //here finding number of subarrays sum less than or equal to goal 
    int n=nums.size();
    int l=0,r=0;
    int sum=0,cnt=0;
    while(r<n){
        sum+=nums[r];
        while(sum>goal){
            sum=sum-nums[l];
            l++;
        }
        cnt=cnt+(r-l+1);
        r++;
    }
    return cnt;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return func3(nums,goal)-func3(nums,goal-1);
    
}

int main(){
    vector<int> nums={1,0,1,0,1};
    int goal=2;
    cout<<numSubarraysWithSum(nums,goal);

}