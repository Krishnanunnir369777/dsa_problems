#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int func1(vector<int>& vec,int k){ // Time complexity O(2*k)
    int lsum=0;
    int n=vec.size();

    for(int i=0;i<k;i++){
        lsum+=vec[i];
    }
    int maxsum=lsum;
    for(int j=0;j<k;j++){
        lsum=lsum-vec[k-1-j]+vec[n-1-j];
        maxsum=max(lsum,maxsum);
    }

    return maxsum;

}

int main(){
    vector<int> vec={6,2,3,4,7,2,1,7,1};
    cout<<func1(vec,4);
}