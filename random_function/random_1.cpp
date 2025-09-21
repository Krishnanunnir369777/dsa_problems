#include <bits/stdc++.h>
using namespace std;

bool canPartition(int n,vector<int>& arr){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    else{
        int target=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        
        
    }
}
int main() {
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    if (canPartition(n, arr))
        cout << "The Array can be partitioned into two equal subsets";
    else
        cout << "The Array cannot be partitioned into two equal subsets";

    return 0;
}