#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void solve(int index,int target,vector<int>& arr,vector<int>& output,vector<vector<int>>& ans){
    if(index==arr.size()){
        if(target==0){
            ans.push_back(output);
        }
        return ;
    }
 // pick up the element 
    if(arr[index]<=target){
        output.push_back(arr[index]);
        solve(index,target-arr[index],arr,output,ans);
        output.pop_back();
    }
    
    solve(index+1,target,arr,output,ans);

}
vector<vector<int>> func(vector<int>& arr, int target){
    vector<vector<int>> ans;
    vector<int> output;
    solve(0,target,arr,output,ans);

    return ans;
}
int main(){
    vector<int> arr={2,3,6,7};
    int target=7;
    vector<vector<int>> ans=func(arr,target);
}