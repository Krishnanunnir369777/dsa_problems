#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int func1(vector<int>& arr) { //Time Complexity: O(N3)
    int maxi = INT_MIN; // maximum sum
    int n=arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;
            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
  
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int func2(vector<int>& arr){  //  O(n^2)
    int maxi=INT_MIN;
    int n=arr.size();

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){

            sum+=arr[j];

            maxi=max(sum,maxi);

        }
    }
    return maxi;               
}

 // kadanes algorithm

int  maxSubarraySum(vector<int>& arr) { // Time Complexity: O(N)
    int n=arr.size();
    int  maxi = INT_MIN; // maximum sum
    int  sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}


int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<func3(nums);
}