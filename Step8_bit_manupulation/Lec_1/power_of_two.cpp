#include <bits/stdc++.h>
using namespace std;

bool func1(int n){

    for(int i=0;i<31;i++){
        if(n==pow(2,i)){
            return true;
        }
    }
    return false;
}

bool func2(int n){

    if(n&n-1 ==0){
        return true;
    }
    return false;
}

int main(){
    cout<<func1(7);
}