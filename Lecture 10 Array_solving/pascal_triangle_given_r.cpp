#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int nCr(int n,int r){
    int res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
void pascaltriangle(int n){  //complexity O(n*r)
    
    for(int c=1;c<=n;c++){
        cout<<nCr(n-1,c-1)<<" ";
    }
}

//optimal

void pascal2(int n){
    long long res=1;

    cout<<res<<" ";

    for(int i=1;i<n;i++){
        res=res*(n-i);
        res=res/i;
        cout<<res<<" ";
    }
}

int main(){
    int n=2;
    pascal2(n);
}