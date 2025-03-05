#include <iostream>
using namespace std;
#include <bits/stdc++.h>


void solve(int index,vector<int>& output,vector<int>& arr,vector<int>& ans){       //Time Complexity: O(2^n)
    if(index==arr.size()){
        int n=output.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=output[i];
        }
        ans.push_back(sum);
        return ;
    }
    
    int element=arr[index];
    output.push_back(element);
    solve(index+1,output,arr,ans);
    
    output.pop_back();
    
    solve(index+1,output,arr,ans);
    
    
}
vector<int> subsetSums1(vector<int>& arr) {
     // code here
     vector<int> ans;
     vector<int> output;
     solve(0,output,arr,ans);
     
     return ans;
}

// optimised 

void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
    if (ind == n) {
      ans.push_back(sum);
      return;
    }
    //element is picked
    subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
    //element is not picked
    subsetSumsHelper(ind + 1, arr, n, ans, sum);
  }
vector < int > subsetSums2(vector < int >& arr) {
    int n=arr.size();
  vector < int > ans;
  subsetSumsHelper(0, arr, n, ans, 0);
  sort(ans.begin(), ans.end());
  return ans;
}
int main(){
    vector < int > arr={3,1,2};
    
    vector < int > ans = subsetSums2(arr);
    sort(ans.begin(), ans.end());
    //cout<<"The sum of each subset is "<<endl;
    for (auto sum: ans) {
      cout << sum << " ";
    }
    cout << endl;
  
    return 0;

}