#include <iostream>
using namespace std;
#include <bits/stdc++.h>



  vector<int> func1(vector<int>A, int n){     // Time Complexity: O(N+N/2)
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // Positives on even indices, negatives on odd.
  for(int i=0;i<n/2;i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
  
  
  return A;
    
}

int main(){
    vector<int> nums={3,1,-2,-5,2,-4};
    vector<int> ans=func(nums);

    for(int i:ans){
        cout<<i<<" ";
    }
}