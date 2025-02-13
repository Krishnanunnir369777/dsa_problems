#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int func1(vector<int>& arr) {     O(n^2)
    // code here
    int n=arr.size();
    int ans=0;
    for(int i=0;i<n;i++){
        long long sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            
            if(sum==0){
                ans=max(ans,j-i+1);
            }
        }
    }
    return ans;
}

int func2(vector<int>& arr) {
    // code here

    int n=arr.size();
    int sum=0;
    map<int,int> mpp;
    int len=0;
    for(int i=0;i<n;i++){
        
        sum+=arr[i];
        
        if(arr[i]==0 && len==0){
            len=1;
        }
        if(sum==0){
            len=i+1;
        }
        if(mpp.find(sum)!=mpp.end()){
            len=max(len,i-mpp[sum]);
        }
        else{
            mpp[sum]=i;
        }
        
    }
    return len;
    

}

int main(){



}