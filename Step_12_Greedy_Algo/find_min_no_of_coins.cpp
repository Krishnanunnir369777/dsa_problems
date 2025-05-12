#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func(vector<int>& coins,int v){
    int n=coins.size();
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        while(v>=coins[i]){
            v-=coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans.size();
}

int main(){
    vector<int> v={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    cout<<func(v,49);
}