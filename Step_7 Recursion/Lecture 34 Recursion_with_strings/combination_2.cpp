#include <iostream>
using namespace std;
#include <bits/stdc++.h>


void solve(int ind,int target,vector<int>& output,vector<int>& arr,vector<vector<int>>& ans){
    if(target==0){
        ans.push_back(output);
        return;
    }
    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]){
            continue;
        }
        if(arr[i]>target){
            break;
        }
        output.push_back(arr[i]);
        solve(i+1,target-arr[i],output,arr,ans);
        output.pop_back();
    }

}
vector<vector<int>> combinationSum2(vector<int>& arr,int target) {
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> output;
    solve(0,target,output,arr,ans);

    return ans;

}
int main() {
    vector<int> v{10,1,2,7,6,1,5};
    vector < vector < int >> comb = combinationSum2(v, 8);
    cout << "[ ";
    for (int i = 0; i < comb.size(); i++) {
      cout << "[ ";
      for (int j = 0; j < comb[i].size(); j++) {
        cout << comb[i][j] << " ";
      }
      cout << "]";
    }
    cout << " ]";
  }