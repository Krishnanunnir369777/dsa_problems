#include <bits/stdc++.h>
using namespace std;

int func1(vector<int>& arr){   //O(n*log(m)) +O(m)    if m is size of map

    map<int,int> mpp;

    for(auto ele:arr){
        mpp[ele]++;
    }

    for(auto it:mpp){
        if(it.second==1){
            return it.first;
        }
    }
    return -1;
}
int func2(vector<int>& arr){          //O(32*n)

    int ans=0;
    for(int i=0;i<32;i++){
        int sum=0;
        for(auto num:arr){
            sum+=(num>>i)&1;
        }
        sum%=3;
        ans=ans|(sum<<i);
    }

    return ans;
}

int singleNumber(vector<int>& nums) {
    int ones=0;                                 //optimised
    int twos=0;

    for(auto num:nums){
        ones=(ones^num)&(~twos);
        twos=(twos^num)&(~ones);
    }

    return ones;
 
}


int main(){
    vector<int> arr={1,1,1,2,2,2,3};
    cout<<func1(arr);
}