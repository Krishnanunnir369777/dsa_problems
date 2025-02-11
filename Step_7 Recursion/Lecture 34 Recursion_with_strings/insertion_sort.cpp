#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void func(int *arr,int n,int i){

    if(i==n){
        return ;
    }
    int j=i;
    while(j>0 && arr[j]<arr[j-1]){
        swap(arr[j],arr[j-1]);
        j--;
    }
    func(arr,n,i+1);


}



int main(){

    int arr[5]={5,4,3,2,7};
    int n=5;
    
    func(arr,n,0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}