#include <iostream>
using namespace std;
#include <bits/stdc++.h>



vector<vector<int>> func1(vector<int>& nums){

    int n=nums.size();

    vector<vector<int>> ans;

    for(int i=0;i<(1<<n);i++){
        
        vector<int> subset;
        for(int j=0;j<n;j++){
            if((i&(1<<j))>0){
                subset.push_back(nums[j]);
            }
        }
        ans.push_back(subset);
    }

    return ans;

}

int main(){
    vector<int> nums={1,2,3};
    vector<vector<int>> ans=func1(nums);

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


}