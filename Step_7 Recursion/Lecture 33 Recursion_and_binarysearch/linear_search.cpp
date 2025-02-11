#include <iostream>
using namespace std;


bool func(int arr[],int n,int k){
    if(n==0){
        return false;
    }
    if(arr[0]==k){
        return true;
    }

    else{
        return func(arr+1,n-1,k);

    }
}







int main(){

    int arr[5]={1,8,3,4,5};
    int n=5;
    int k=2;
    if(func(arr,n,k)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }



}