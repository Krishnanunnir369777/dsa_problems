#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int fibonacci_series(int n){
    // base case
    if(n==0){
        
        return 0;
    }
    if(n==1){
        return 1;
    }

    
    
    return fibonacci_series(n-1)+fibonacci_series(n-2);   //  time complexity O(2^n)
                                                          // space complexity O(n)
    
    
    


}

int main(){

    int n;
    cin>>n;
    cout<<fibonacci_series(n);






}