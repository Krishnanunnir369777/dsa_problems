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



int main(){
    vector<int> nums={1,0,1,0,1};
    int goal=2;
    cout<<func1(nums,goal);

}