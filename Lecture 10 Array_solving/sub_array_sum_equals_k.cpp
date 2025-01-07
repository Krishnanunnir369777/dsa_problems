#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int func1(vector<int>& arr,int k){
    int n=arr.size();
    int ans=0;
    
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                ans++;
               
            }

        }
    }
    return ans;

}

int main(){
    vector<int> arr={1,2,3};
    cout<<func1(arr,3);
}