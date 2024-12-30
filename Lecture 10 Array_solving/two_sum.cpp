#include <iostream>
using namespace std;
#include <bits/stdc++.h>


vector<int> func1(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}
vector<int> func2(vector<int>& nums,int target){  // time complexity will be O(N* logN) 
    int n=nums.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a=nums[i];
        int more=target-a;
        if(mpp.find(more)!=mpp.end()){
            return {mpp[more],i};
        }
        mpp[a]=i;
    }
    return {-1,-1};



}


int main(){
    vector<int> nums={2,7,11,15};
    int tar=9;
    vector<int> ans=func2(nums,tar);
    for(int i:ans){
        cout<<i<<" ";
    }
}