#include <iostream>
using namespace std;


bool func1(string s,int i,int j){
    // base case
    if(i>j){
        return true;
    }
    if(s[i]!=s[j]){
        return false;
    }
    i++;
    j--;
    return func1(s,i,j);
}


int main(){
    string s="abc";
    int n=s.length();
    cout<<func1(s,0,n-1);



}