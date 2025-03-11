#include <bits/stdc++.h>
using namespace std;

void func(int a,int b){

    a=a^b;
    b=a^b;
    a=a^b;

    cout<<"a is "<<a<<" "<<"b is "<<b;
}

int main(){
    int a=2;
    int b=3;
    func(a,b);
    
}