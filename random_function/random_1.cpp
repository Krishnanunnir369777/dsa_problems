#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void func(int i,int n){
    if(i>n) return ;
    func(i+1,n);
    cout<<i<<endl;
    
}

int main(){
    int n=4;
    func(1,n);
}
