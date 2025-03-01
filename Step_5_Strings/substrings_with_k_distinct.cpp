#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int func1(string& s,int k){

    int n=s.length();
    int ans=0;
    
    for(int i=0;i<n;i++){

        int arr[26]={0};
        int count=0;
        for(int j=i;j<n;j++){

            if(arr[s[j]-'a']==0){
                count++;
            }
            arr[s[j]-'a']++;

            if(count==k){
                ans++;
            }
            if(count>k){
                break;
            }

        }
    }
    return ans;
}

int main(){ 
    string s="aba";
    int k=2;
    cout<<func1(s,k);
}