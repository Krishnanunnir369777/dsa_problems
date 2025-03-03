#include <iostream>
using namespace std;
#include <bits/stdc++.h>

long long func1_1(int b,int exp){
    long long ans=1;
    long long base =b;
    while(exp>0){
        if(exp%2){
            exp--;
            ans=ans*base;
        }
        else{
            exp/=2;
            base=base*base;
        }
    }
    return ans;

}
int func1(int n, int m) {   // O(n)
    //Use linear search on the answer space:
    for (int i = 1; i <= m; i++) {
        long long val = func1_1(i, n);
        if (val == m * 1ll) return i;
        else if (val > m * 1ll) break;
    }
    return -1;
}
int func2_2(int mid,int n,int m){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*mid;
        if(ans>m){
            return 2;
        }
    }
    if(ans==m){
        return 1;
    }
    return 0;
}
int func2(int n,int m){
    int s=1;
    int e=m-1;
    while(s<=e){
        int mid=(s+e)/2;
        int midN=func2_2(mid,n,m);
        if(midN==1){
            return mid;
        }
        else if(midN==0){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return -1;
}
int main(){
    int n = 3, m = 26;
    int ans = func2(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}