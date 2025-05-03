#include <iostream>
using namespace std;
#include <bits/stdc++.h>


void bitOperations(unsigned int num, int i) {
    // Convert 1-based index to 0-based index
    int bitPos = i - 1;
    
    // Get ith bit
    int ithBit = (num >> bitPos) & 1;
    
    // Set ith bit
    unsigned int setBitNum = num | (1 << bitPos);
    
    // Clear ith bit
    unsigned int clearBitNum = num & ~(1 << bitPos);
    
    // Print results in required format
    cout << ithBit << " " << setBitNum << " " << clearBitNum;
}

int main() {
    unsigned int num;
    int i;
    cin >> num >> i;
    bitOperations(num, i);
    return 0;
}
