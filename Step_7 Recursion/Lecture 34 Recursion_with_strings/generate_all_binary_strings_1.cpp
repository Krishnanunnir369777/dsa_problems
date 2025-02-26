#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void generateBinaryStrings(int N, string binaryString = "") {

    if (binaryString.length() == N) {
        for (char c : binaryString) 
            cout << c << " ";
        cout << endl;
        return;
    }
    
    generateBinaryStrings(N, binaryString + "0");
    generateBinaryStrings(N, binaryString + "1");
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;
    
    generateBinaryStrings(N);
    
    return 0;
}