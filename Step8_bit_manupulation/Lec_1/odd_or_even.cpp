#include <bits/stdc++.h>
using namespace std;

bool func(int n){

    if(n&1){
        return false;//means odd
    }

    return true; // means even
}
int main(){
    cout<<func(15);
}