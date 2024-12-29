#include<iostream>
using namespace std;
int  sorted_rotated(int arr[],int n){
    int count =0;
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            count+=1;
        }
    }
    if(arr[n-1]>arr[0]){
        count+=1;
    }
    return count;
}
int main(){
    int arr[5]={5,1,2,3,4};
    int n=5;
    int ans=sorted_rotated(arr,n);
    if(ans==1 or ans<1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }


}