#include <bits/stdc++.h>
using namespace std;



int divide(int dividend, int divisor) {
    if(dividend==divisor){
        return 1;
    }
    bool sign=true;
    if((dividend>=0 && divisor<0) || (dividend<=0 && divisor>0)){
        sign=false;
    }
    long n=abs((long) dividend);
    long d=abs((long) divisor);
    long q=0;
    while(n>=d){
        int cnt=0;
        while(n>=(d<<(cnt+1))){
            cnt++;
        }
        q+=(1<<cnt);
        n-=(d<<cnt);
    }
    if(q==(1<<31) && sign){
        return INT_MAX;
    }
    if(q==(1<<31) && !sign){
        return INT_MIN;
    }

    return sign ? q :-q;
    
}
int main(){
    int dvidend=10;
    int div=3;

    cout<<divide(22,3);

}