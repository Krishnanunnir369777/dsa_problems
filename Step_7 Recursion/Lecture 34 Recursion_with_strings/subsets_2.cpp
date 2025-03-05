#include <bits/stdc++.h>
using namespace std;


set<vector<int>> st;
void solve1(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
    //base case
    if(index>=nums.size()){
        sort(output.begin(),output.end());
        st.insert(output);
        return ;
    }

    //exclude
    solve1(nums,output,index+1,ans);

    //include
    int element=nums[index];
    output.push_back(element);
    solve1(nums,output,index+1,ans);
}
vector<vector<int>> func1(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve1(nums,output,index,ans);
    int n=st.size();
    for(auto i:st){
        ans.push_back(i);
    }


    return ans;

}

void solve2(int ind, vector < int > & nums, vector < int > & ds, vector < vector < int >> & ans) {
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++) {
       if (i != ind && nums[i] == nums[i - 1]) continue;
       ds.push_back(nums[i]);
       solve2(i + 1, nums, ds, ans);
       ds.pop_back();
    }
 }

 vector < vector < int >> func2(vector < int > & nums) {
    vector < vector < int >> ans;
    vector < int > ds;
    sort(nums.begin(), nums.end());
    solve2(0, nums, ds, ans);
    return ans;
 }



 int main(){
    vector < int > nums = {1,2,2 };
    vector < vector < int >> ans = func1(nums);
    
 }