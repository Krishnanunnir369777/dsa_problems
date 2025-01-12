#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int func1(vector<int> arr){   // time complexity O(n)
    int n=arr.size();
    int mini=arr[0];

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            mini=arr[i+1];
            break;
        }
    }
    return mini;
}
int func2(vector<int> &arr){  //O(log(n))
    int n=arr.size();
    int mini=INT_MAX;
    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=(s+e)/2;

        ////if left part is sorted:
        if(arr[s]<=arr[mid]){
            mini=min(mini,arr[s]);
            s=mid+1;
        }
        else{

            mini=min(mini,arr[mid]);
            e=mid;
        }
    }
    return mini;

}

int main(){

    vector<int> arr={3,4,5,1,2};
    cout<<func2(arr);
}