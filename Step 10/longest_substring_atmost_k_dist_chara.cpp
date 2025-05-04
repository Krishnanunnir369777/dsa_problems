#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int func1(string s,int k){   //O(n^2)
    int n=s.length();
    int maxlen=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int> mpp;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            if(mpp.size()>k){
                maxlen=max(maxlen,j-i);
                break;
            }
            maxlen=max(maxlen,j-i+1);

        } 
    }
    return maxlen;
}

int func2(string s,int k){   //O(2n)
    int n=s.length();
    int r=0,l=0;
    int maxlen=0;
    unordered_map<char,int> mpp;
    while(r<n){
        mpp[s[r]]++;
        if(mpp.size()>k){
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
        }
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
}

int func3(string s,int k){
    int n=s.length();
    int r=0,l=0;
    int maxlen=0;
    unordered_map<char,int> mpp;
    while(r<n){
        mpp[s[r]]++;
        if(mpp.size()>k){
            mpp[s[l]]--;
            if(mpp[s[l]]==0){
                mpp.erase(s[l]);
            }
            l++;
        }
        if(mpp.size()<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}
int main(){
    string s="aaabbccd";
    cout<<func3(s,1);
}