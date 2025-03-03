#include <iostream>
using namespace std;
#include <bits/stdc++.h>
unordered_set<string> sn;
void solve(string s,string output,int idx){
    if(idx>=s.length()){
        if(output.length()>0){
            sn.insert(output);
            
        }
        return ;
    }
        
        //exclude
        solve(s,output,idx+1);
        
        // include 
        char element=s[idx];
        output.push_back(element);
        solve(s,output,idx+1);
    
}
void subsequence(string s){
    
    string output="";
    int idx=0;
    solve(s,output,idx);

}
int main(){
    string s1="g";
    string s2="a";
    subsequence(s1);
    int a=sn.size();
    sn.clear();

    subsequence(s2);
    int b=sn.size();
    sn.clear();

    if(b>a){
        cout<<2;
    }
    else{
        cout<<1;
    }
    

}
