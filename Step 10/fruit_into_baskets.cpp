#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int func1(vector<int>& fruits) { //0(n^2)
    int n=fruits.size();
    int maxlen=0;
    for(int i=0;i<n;i++){
        unordered_map<int, int> mpp;
        for(int j=i;j<n;j++){
            mpp[fruits[j]]++;
            if(mpp.size()>2){
                maxlen=max(maxlen,j-i);
                break;
            }
            maxlen=max(maxlen,j-i+1);
        }
    }
    return maxlen;
    
}

int func2(vector<int>& fruits) {  //O(2n)
    int n=fruits.size();
    int r=0,l=0;
    int maxlen=0;
    unordered_map<int,int>count;
    while(r<n){
        count[fruits[r]]++;
        while(count.size()>2){
            count[fruits[l]]--;
            if(count[fruits[l]]==0){
                count.erase(fruits[l]);
            }
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return maxlen;
    
}

int func3(vector<int>& fruits){
    int n=fruits.size();
    int r=0,l=0;
    int maxlen=0;
    unordered_map<int,int>mpp;
    while(r<n){
        mpp[fruits[r]]++;
        if(mpp.size()>2){
            mpp[fruits[l]]--;
            if(mpp[fruits[l]]==0){
                mpp.erase(fruits[l]);
            }
            l++;
        }
        if(mpp.size()<=2){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    return maxlen;
}
int main(){
    vector<int> v={1,2,1,4,4,4};
    cout<<func2(v);

}