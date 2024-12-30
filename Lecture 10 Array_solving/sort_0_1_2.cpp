#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void func1(vector<int> &arr){ //Time Complexity: O(N) + O(N
    int n=arr.size();
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            cnt0++;
        }
        if(arr[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    for(int i=0;i<cnt0;i++){
        arr[i]=0;
    }
    for(int i=cnt0;i<(cnt0+cnt1);i++){
        arr[i]=1;
    }
    for(int i=(cnt0+cnt1);i<n;i++){
        arr[i]=2;
    }


}

void sortArray(vector<int>& arr, int n) { //optimized 
                                        // Time Complexity: O(N)

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


int main(){
    vector<int> nums={2,0,2,1,1,0};
    func1(nums);
    for(int i:nums){
        cout<<i<<" ";
    }

}