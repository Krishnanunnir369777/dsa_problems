#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<int> func1(vector<int>& arr){  //Time Complexity: O(N^2)
    int n=arr.size();
    int left=0;
    int rigth=n-1;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int a=1;
        for(int j=n-1;j>i;j--){
            if(arr[i]<arr[j]){
                a=-1;
            }
        }
        if(a==1){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> func2(vector<int>& arr) {

    int n=arr.size();

  vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
 int max = arr[n - 1];
 ans.push_back(arr[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] >=max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }

  
  return ans;
}


int main(){
    vector<int> arr={16,17,4,3,5,2};
    vector<int> ans=func2(arr);
    for(int i:ans){
        cout<<i<<" ";
    }
}