#include <iostream>
using namespace std;
#include <bits/stdc++.h>


void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
    //base case
    if(index>=nums.size()){
        ans.push_back(output);
        return ;
    }

    //exclude
    solve(nums,output,index+1,ans);

    //include
    int element=nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);
}


vector<vector<int>> subsets(vector<int>& nums){

    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(nums,output,index,ans);
    return ans;

}
int main(){
    vector<int> arr={5, 2, 3, 10, 6, 8};
    int target=10;
    int ans=0;
    vector<vector<int>> ans=subsets(arr);
    for(auto it:ans;){
        int sum=0;
        for(auto i:it;i){
            sum+=i;
            if(sum==target){
                ans++;

            }
            
        }
    }
    cout<<ans;

}