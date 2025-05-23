#include <bits/stdc++.h>
using namespace std;

int func(vector<int>& arr){
    int ans=0;

    for(int i=0;i<arr.size();i++){
        ans=ans^arr[i];
    }

    return ans;
}

int main(){
    vector<int>arr={1,1,2,2,3};

    cout<<func(arr);

}