#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
    // if all bits of 'n' are set
    // the number is of form 2^k -1 return n
    if (!(n & (n + 1)))
        return n;
    // else
    return n | (n + 1);
}
int main(){
    cout<<func(4);
    
}