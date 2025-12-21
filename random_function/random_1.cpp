#include <bits/stdc++.h>
using namespace std;



// Driver code
int main() {
    int n=17;
    vector<int> ans;
    
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n!=1){
        ans.push_back(n);
    }
    for(int i:ans){
        cout<<i<<" ";
    }
    
}