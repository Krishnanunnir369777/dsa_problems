#include<bits/stdc++.h>
using namespace std;


vector<int> func1(vector<int>& nums) {   //O(n^2)
    int n=nums.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool add=false;
        for(int j=i+1;j<2*n-1;j++){
            int idx=j%n;
            if(nums[idx]>nums[i]){
                ans.push_back(nums[idx]);
                add=true;
                break;
            }
        }
        if(add==false){
            ans.push_back(-1);

        }
    }
    return ans;
      
}


vector<int> func2(vector<int>& nums) {    //O(n^2)
    int n=nums.size();
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top()<=nums[i%n]){
            st.pop();
        }
        if(i<n){
            if(!st.empty()){
                ans[i]=st.top();
            }
        }
        st.push(nums[i%n]);
    }

    return ans;
      
}

int main(){
    vector<int> vec={1,2,3,4,3};
    vector<int>ans=func2(vec);
    for(auto it:ans){
        cout<<it<<" ";
    }
}