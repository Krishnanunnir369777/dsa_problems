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


int main(){
    vector<int>arr={1,2,1,2,3};
    int k=2;
    cout<<func1(arr,k);
}