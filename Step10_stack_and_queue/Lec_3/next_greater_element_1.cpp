#include <bits/stdc++.h>
using namespace std;



vector<int> func1(vector<int>& nums1, vector<int>& nums2) {

    vector<int> ans;
    for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            if(nums1[i]==nums2[j]){
                int k=j;
                k++;
                if(k>=nums2.size()){
                    ans.push_back(-1);
                    break;
                }
                bool exist=false;
                for(k;k<nums2.size();k++){
                    if(nums2[k]>nums2[j]){
                        ans.push_back(nums2[k]);
                        exist=true;
                        break;
                    }
                }
                if(exist==false){
                    ans.push_back(-1);
                }
                break;
            }
        }
    }
    return ans;
    
}

vector<int> func2(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    for(int i=0;i<nums1.size();i++){
        int max=-1;
        for(int j=0;j<nums2.size();j++){
            int index=j;
            if(nums1[i]==nums2[j]){ // Found element in nums2 that matches current element in nums1
                 while(index!=nums2.size()){ // Iterate through remaining elements in nums2 to find next greater element
                    if(nums2[index]>nums1[i]){
                        max=nums2[index]; // Update max if we find a greater element
                        break;
                    }
                    index++;
                }
           }
        }
        ans.push_back(max);
    }
    return ans;

}

    
vector<int> func3(vector<int>& nums1, vector<int>& nums2) {    //Time Complexity: O(n + m)
    unordered_map<int,int> mpp;
    stack<int> st;
    for(int i=nums2.size()-1;i>=0;i--){
        while(!st.empty() && nums2[i]>st.top()){
            st.pop();
        }
        if(st.empty()){
            mpp[nums2[i]]=-1;
        }
        else{
            mpp[nums2[i]]=st.top();
        }
        st.push(nums2[i]);
    }
    vector<int> ans;
    for(int j=0;j<nums1.size();j++){
        ans.push_back(mpp[nums1[j]]);
    }

    return ans;
}


int main(){


}