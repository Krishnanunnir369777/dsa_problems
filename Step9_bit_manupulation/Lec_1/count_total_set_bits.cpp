#include<bits/stdc++.h>
using namespace std;

int count_ones_1(int n){   // time complexity  O(N*logN)
    int cnt=0;

    while(n>0){
        if(n&1==1){
            cnt++;
        }
        n=n>>1;
    }
    return cnt;
}
int count_ones_2(int n){
    int cnt=0;
    while(n){
        n=n&n-1;
        cnt++;
    }
    return cnt;
}
int func1(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=count_ones_2(i);

    }
    return sum;
}


int func2(int n)           //O(log(n))
{
    //Ignoring 0 as all the bits are unset. 
    n++;
    int count=0;
    
    //Counting set bits from 1 to n.
    for( int x=2 ; x/2<n ; x=x*2 )
    {
        //Total count of pairs of 0s and 1s.
        int quotient = n/x;
        //quotient gives the complete count of pairs of 1s.
        //Multiplying it with the (current power of 2)/2 will 
        //give the count of 1s in the current bit.
        count += quotient * x / 2;
        
        int remainder = n%x;
        //If the count of pairs is odd then we add the remaining 1s 
        //which could not be grouped together. 
        if(remainder > x/2)
            count += remainder - x/2;
    }
    
    //returning count of set bits.
    return count;
}
int main(){
    cout<<func1(4);
}