#include <iostream>
using namespace std;

bool is_sorted(int arr[],int n){

    // base case
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remain_part=is_sorted(arr+1,n-1);
        return remain_part;
    }



}
int main(){
    int arr[5]={1,2,3,5,4};
    int n=5;
    if(is_sorted(arr,n)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}