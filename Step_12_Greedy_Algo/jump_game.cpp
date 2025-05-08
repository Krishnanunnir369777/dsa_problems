#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool canJump(vector<int>& nums) {
    int n= nums.size();
    int maxIndex=0;

    for(int i=0;i<n;i++){
        if(i>maxIndex){
            return false;
        }

        maxIndex=max(maxIndex,nums[i]+i);
    }
    return true;
}

int main(){
    vector<int> v={1,2,3,4,5};
    cout<<canJump(v);
}