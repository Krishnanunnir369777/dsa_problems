#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void func(int n,string arr[]){

    // base case
    if(n==0){
        return ;
    }
    int digit=n%10;
    n=n/10;
    //cout<<arr[digit]<<" ";
    func(n,arr);
    cout<<arr[digit]<<" ";
}
int main(){

    int n;
    cin>>n;
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

    func(n,arr);




}