#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int func1(vector<int> &nums){
    int maxi=0;
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++){
        
        if(nums[i]==1){
            count+=1;
            
        }
        else{
            
            count=0;
        }
        maxi=max(maxi,count);
        
    }
    
    return maxi;
}


int main(){
    vector<int> nums={1,0,1,1,0,1};
    cout<<func1(nums);

}