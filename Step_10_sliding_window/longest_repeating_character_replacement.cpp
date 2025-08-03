#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int func1(string s, int k) {  //O(N^2)
    int n=s.length();
    int maxlen=0;
    for(int i=0;i<n;i++){
        vector<int> hash(26,0);
        int maxj=0;
        for(int j=i;j<n;j++){
            hash[s[j]-'A']++;
            maxj=max(maxj,hash[s[j]-'A']);
            int changes=(j-i+1)-maxj;
            if(changes<=k){
                maxlen=max(maxlen,j-i+1);
            }
            else{
                break;
            }
        }
    }
    return maxlen;
}



int func2(string s, int k) {  //O(n+n)*26
    int n=s.length();
    int l=0,r=0;
    int maxlen=0,maxfreq=0;
    vector<int> v(26,0);
    while(r<n){
        v[s[r]-'A']++;
        maxfreq=max(maxfreq,v[s[r]-'A']);
        while((r-l+1)-maxfreq>k){
            v[s[l]-'A']--;
            maxfreq=0;
            for(int i=0;i<26;i++){
                maxfreq=max(maxfreq,v[i]);
            }
            l++;
        }
        if((r-l+1)-maxfreq<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}

int func3(string s, int k) {  //O(n)  // more optimised
    int n=s.length();
    int l=0,r=0;
    int maxlen=0,maxfreq=0;
    vector<int> v(26,0);
    while(r<n){
        v[s[r]-'A']++;
        maxfreq=max(maxfreq,v[s[r]-'A']);
        if((r-l+1)-maxfreq>k){
            v[s[l]-'A']--;
            maxfreq=0;
            l++;
        }
        if((r-l+1)-maxfreq<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}


int main(){
    string s="AABABBA";
    int k=1;
    cout<<func3(s,k);
}