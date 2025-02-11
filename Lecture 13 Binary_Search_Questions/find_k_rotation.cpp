#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int func1(vector<int> &arr) {        //O(n)
    // Code Here
    int n=arr.size();
    int ans=0;
    int pos=0;
    while(pos<n-1){
        if(arr[pos]>arr[pos+1]){
            ans=pos+1;
            break;
        }
        pos++;
    }
    return ans;
    
}

int func2(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}

int main(){
    vector<int> arr={6,8,10,2,4};
    cout<<func1(arr);

}