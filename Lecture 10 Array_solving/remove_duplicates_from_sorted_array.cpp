#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int func1(vector<int> &nums){//Time complexity: O(n*log(n))+O(n)
                            // Space Complexity: O(n) 
    int n=nums.size();
    set<int> set;
    for(int i=0;i<n;i++){
        set.insert(nums[i]);
    }
    int k=set.size();
    int j=0;
    for(int x:set){
        nums[j++]=x;
    }
    return k;
}
int func2(vector<int> &nums){  // O(n)
    int n=nums.size();
    int count=1;
    if(n==0){
        return 0;
    }
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            count+=1;
        }
    }
    int correct_index=1;
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            nums[correct_index++]=nums[i];
        }
    }
    return count;

}

int main(){
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    cout<<func2(nums)<<endl;
    for(int i:nums){
        cout<<i<<" ";
    }
}