#include <iostream>
using namespace std;
#include <bits/stdc++.h>

bool checkpal(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
string func1(string& s){   //O(n^3)
    int n=s.size();

    int maxlen=1,start=0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            if(checkpal(s,i,j) && (j-i+1)>maxlen){
                start=i;
                maxlen=j-i+1;
            }
        }
    }
    return s.substr(start,maxlen);

}
string func2(string &s){       //O(n^2)
    int n=s.size();
    if(n==0){
        return "";
    }
    int start=0,maxlen=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<=1;j++){
            int low=i;
            int high=i+j;

            while(low>=0 && high<n && s[low]==s[high]){
                int currlen=high-low+1;
                if(currlen>maxlen){
                    start=low;
                    maxlen=currlen;
                }
                low--;
                high++;
            }

        }
    }
    return s.substr(start,maxlen);

}
int main(){
    string s="babad";
    string ans=func2(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}