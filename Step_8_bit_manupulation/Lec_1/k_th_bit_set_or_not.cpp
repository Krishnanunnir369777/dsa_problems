#include <bits/stdc++.h>
using namespace std;

bool func(int n,int k){

    int ans=(n>>k)&1;

    return ans;
}

int main(){
    cout<<func(4,2);
}