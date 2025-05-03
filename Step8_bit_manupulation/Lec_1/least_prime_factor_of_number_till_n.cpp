#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void leastprimefactor(int n){

    vector<int> least_prime(n+1,0);
    least_prime[1]=1;

    for(int i=2;i<=n;i++){
        if(least_prime[i]==0){
            
            least_prime[i]=i;

            for(int j=i*i;j<=n;j+=i){
                least_prime[j]=i;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << "Least Prime factor of "
             << i << ": " << least_prime[i] << "\n";


}

int main(){
    int n=10;
    leastprimefactor(n);

    return 0;
}