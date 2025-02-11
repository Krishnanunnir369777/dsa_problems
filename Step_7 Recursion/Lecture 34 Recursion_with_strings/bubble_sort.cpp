#include <iostream>
using namespace std;

void func(int *arr,int n){
    //base case - already sorted
    if(n==0 || n==1){
        return ;
    }

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    func(arr,n-1);

}

int main(){
    int arr[5]={2,3,5,6,1};
    func(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}