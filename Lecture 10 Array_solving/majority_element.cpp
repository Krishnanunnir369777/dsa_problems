#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int func1(vector<int> &arr){  //O(z)
    int n=arr.size();
    int ans=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>(n/2)){
            ans=arr[i];
        }
    }
    return ans;
}

int func2(vector<int> &arr){
    map<int,int>mpp; // N*log(N)
    int n=arr.size();
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second>(n/2)){
            return it.first;
        }
    }
    return -1;
}

int func3(vector<int> &arr){ //Time Complexity: O(N) + O(N), where N = size of the given array.
    int cnt=0;
    int ele=0;
    int n=arr.size();

    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            ele=arr[i];
        }
        else if(arr[i]==ele){
            cnt++;
        }
        else{
            cnt--;
        }
    }   
    int cnt1=0;

    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            cnt1++;
        }
    }
    if(cnt1>(n/2)){
        return ele;
    }
    return -1;
}

int main(){
    vector<int> nums={3,2,3};
    cout<<func3(nums);
}