#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> func1(vector<int>& nums){   //O(n)
    int n=nums.size();

    vector<int> ans;
    ans.push_back(-1);
    if(n==1 || n==0){
        return ans;
    }
    for(int i=1;i<n;i++){
        bool done=false;
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i]){
                done=true;
                ans.push_back(nums[j]);
                break;
            }
        }
        if(done==false){
            ans.push_back(-1);
        }
    }
    return ans;
}

vector<int> func2(vector<int>& nums){       //O(n)
    int n=nums.size();
    stack<int> st;
    vector<int> ans;

    for(int i=0;i<n;i++){
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
    return ans;
    
}

int main(){
    vector<int> nums={1,2,3};
    vector<int>ans=func2(nums);
    for(auto it:ans){
        cout<<it<<" ";
    }

}