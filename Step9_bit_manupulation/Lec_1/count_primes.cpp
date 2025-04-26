#include <iostream>
using namespace std;
#include <bits/stdc++.h>


bool find_prime(int n){
    if(n==2){
        return true;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;

}
int func1(int n) {
    int ans=0;
    for(int i=2;i<n;i++){
        if(find_prime(i)){
            ans++;
        }

    }
    return ans;
}
int func2(int n) {       //Time complexity: O(nloglogn)
    int cnt = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            cnt++;
            for (int j = i * 2; j < n; j = j + i) {
                prime[j] = 0;
            }
        }
    }
    return cnt;
}

int func3(int n) {
    if (n <= 2) return 0;

    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }

    return count(prime.begin(), prime.end(), true);
}
int main(){
    int n=3;
    cout<<func1(n);

}