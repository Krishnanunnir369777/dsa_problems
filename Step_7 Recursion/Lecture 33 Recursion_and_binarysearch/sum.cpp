#include <iostream>
using namespace std;

int func(int *arr,int n){
    int sum=0;
    if(n==0){
        return 0;
    }
    if(n==1){
        return arr[0];
    }
    else{
        sum=arr[0]+func(arr+1,n-1);
    }
    return sum;
}
int main(){

    int arr[5]={1,2,3,4,5};
    int n=5;
    cout<<func(arr,5);
}