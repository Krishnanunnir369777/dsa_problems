#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int func1(int start, int goal) {  //Time Complexity: O(max bits)

    int cnt=0;

    while(start>0 || goal >0){
        if((start&1)!=(goal&1)){
            cnt++;
        }

        start>>=1;
        goal>>=1;
    }

    return cnt;
    
}

int func2(int start, int goal) {  //Time complexity: O(number of bits)

    int result=start^goal;
    int cnt=0;
    while(result){
        cnt+=result&1;
        result>>=1;
    }

    return cnt;
    
}

int func3(int start, int goal) {
    // XOR to find differing bits
    int xorResult = start ^ goal;
    int count = 0;
    // Brian Kernighans algorithm to count 1s
    while (xorResult) {
        xorResult &= (xorResult - 1);  // Clear the lowest set bit
        count++;
    }
    return count;
}

int main(){
    cout<<func3(10,7);
}