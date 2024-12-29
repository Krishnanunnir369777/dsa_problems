#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void better_approach(vector<int> &arr){

    int count=0;

    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0){
            swap(arr[i],arr[count++]);
      }
    }
    
}


int main(){
    
    vector<int> arr={0,1,0,3,4};
    better_approach(arr);
    for(int i:arr){
        cout<<i<<" ";
    }



}