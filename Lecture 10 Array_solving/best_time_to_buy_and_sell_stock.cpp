#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int func1(vector<int> &arr){//[Naive Approach] By exploring all possible pairs – O(n^2) Time and O(1) Space
    int n=arr.size();
    int res=0;
    // Explore all possible ways to buy and sell stock
    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){

            res=max(res,arr[j]-arr[i]);
        }
    }
    return res;
}
int func2(vector<int> arr){

    int n=arr.size();
    int minsofar=arr[0],ans=0;

    for(int i=1;i<n;i++){
        // Update the minimum value seen so
        // far if we see smaller
        minsofar=min(minsofar,arr[i]);
        // Update result if we get more profit 
        ans=max(ans,arr[i]-minsofar);
    }
    return ans;
}
int main(){
    vector<int> arr={7,1,5,3,6,4};
    int n=func2(arr);
    cout<<n;

 }