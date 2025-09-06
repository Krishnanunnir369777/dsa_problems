#include <bits/stdc++.h>
using namespace std;

bool func(int idx,int k,vector<int>& arr){
    if(k==0){
        return true;
    }
    if(idx==0){
        return arr[idx]==k;
    }
    bool pick=func(idx-1,k,arr);
    bool un_pick=false;
    if(k>=arr[idx]){
        un_pick=func(idx-1,k-arr[idx],arr);
    }
    return pick || un_pick;

}