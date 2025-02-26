#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void generateBinaryStrings(int k,string binarystring="",char prev='0'){
    if(binarystring.length()==k){
        cout<<binarystring<<endl;
        return;
    }
    generateBinaryStrings(k,binarystring+'0','0');

    if(prev=='0'){
        generateBinaryStrings(k,binarystring+'1','1');
    }


}
int main() {
    int K = 3;
    generateBinaryStrings(K);
    
    cout << "------" << endl;
    
    K = 4;
    generateBinaryStrings(K);

    return 0;
}