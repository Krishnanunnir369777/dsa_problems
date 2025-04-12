#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<int> func(vector<int>& nums){
    int n=nums.size();
    stack<int> st;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>nums[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(st.top());
        }
        st.push(nums[i]);
    }
    reverse(ans.begin(),ans.end());

    return ans;
}
int main(){
    vector<int> arr={3,2,1};
    vector<int> ans=func(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }
    
    

}