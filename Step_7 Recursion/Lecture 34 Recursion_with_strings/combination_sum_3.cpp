#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void solve(int k,int n,int ind,vector<int>& output,vector<vector<int>>& ans){
    if(n==0 && k==output.size()){
        ans.push_back(output);

        return ;
    }
    if(n<0 || output.size()>k) return ;

    for(int i=ind;i<=9;i++){
        output.push_back(i);
        solve(k,n-i,i+1,output,ans);// Move to next number
        output.pop_back();// Backtrack
    }
}

vector<vector<int>> combinationSum3(int k,int n){
    vector<vector<int>> ans;
    vector<int> output;

    solve(k,n,1,output,ans);
    return ans;
}
int main() {
    int k = 3, n = 9;
    vector<vector<int>> result = combinationSum3(k, n);
    
    cout << "Valid combinations:\n";
    for (const auto &comb : result) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]\n";
    }
    return 0;
}