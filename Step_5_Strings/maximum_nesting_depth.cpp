#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int func1(string s) {
    int n=s.length();
    int ans=0;
    int count=0;
    for(int i=0;i<n;i++){
         if(s[i]=='('){
            count++;
            ans=max(ans,count);
         }
         if(s[i]==')'){
            count--;
            ans=max(ans,count);
         }
    }
    return ans;  
}
int main(){

    string s="(1+(2*3)+((8)/4))+1";
    cout<<func1(s);

}