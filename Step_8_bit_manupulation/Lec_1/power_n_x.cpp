#include <bits/stdc++.h>
using namespace std;

double func(double x,int n){
    double pow=1;
    if(n<0){
        x=1/x;
    }
    long num=labs(n);
    while(num){
        if(num&1){
            pow*=x;
        }
        x*=x;
        num=num>>1;
    }
    return pow;
}


int main(){
    double x=2.0000;
    int n=10;
    cout<<func(x,n);
}