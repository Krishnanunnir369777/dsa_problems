#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int func(int n){
    int i=0,ans=0;
    while(n>0){
        int bit=n&1;
        ans=ans+bit*pow(10,i);
        i++;
        n=n>>1;
    }
    return ans;
}
int main(){
    cout<<func(5);
}
