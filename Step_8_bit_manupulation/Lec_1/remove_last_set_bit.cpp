#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int func(int n){

    return n & n-1;
}
int main(){
    cout<<func(5);
}