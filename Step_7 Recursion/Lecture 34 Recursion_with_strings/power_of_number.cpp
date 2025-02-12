#include <iostream>
using namespace std;

int pow(int a,int b){

    //base case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans=pow(a,b/2);

    //even
    if(b%2==0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}


// O(log(n))

double myPow(double x, int n) {
        
    if(n < 0) {
        x = 1 / x;
    } 
    
    long num = labs(n);
    
    double pow = 1;
    
    while(num){ // equivalent to while(num != 0)
        if(num & 1) { // equivalent to if((num & 1) != 0)
            pow *= x;
        }
        
        x *= x;
        num >>= 1;
    }
    
    return pow;
}


int main(){

    int a,b;
    cin>>a>>b;
    cout<<pow(a,b);



}