#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int power(int n){

    if(n==0){
        return 1;
    }

    //int ans=(2)*power(n-1);

    return (2)*power(n-1); ;
}
int main(){

    int n;
    cin>>n;

    int ans=power(n);
    cout<<ans;
}