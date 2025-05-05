#include <bits/stdc++.h>
using namespace std;
#include <iostream>


int func1(string s) {  //O(N^2)
    int cnt=0;
    int n=s.length();
    if(n<3){
        return 0;
    }
    for(int i=0;i<n-2;i++){
        unordered_map<char,int> mpp;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            if(mpp.size()==3){
                cnt=cnt+(n-j);
                break;
            }
        }
    }
    return cnt;
    
}


int func2(string s){
    int n=s.length();
    int cnt=0;
    vector<int> v(3,-1);
    for(int i=0;i<n;i++){
        v[s[i]-'a']=i;

        if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1){
            cnt=cnt+1+min({v[0],v[1],v[2]});
        }
    }
    return cnt;
}

int func2(string s){
    int n=s.length();
    vector<int> v(3,-1);
    for( int )
}
int main(){
    string s="abcabc";
    cout<<func1(s);
}