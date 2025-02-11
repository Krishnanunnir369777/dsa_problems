#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int func1(int n){
    // base case

    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans=0;
    ans=func1(n-1)+func1(n-2);

    return ans;
}
int main(){

    int n;
    cin>>n;
    cout<<func1(n);



}