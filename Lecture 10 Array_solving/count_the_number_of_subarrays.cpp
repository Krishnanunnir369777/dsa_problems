#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int func1(vector<int> a, int k) {      //O(n^2)
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int func2(vector<int> &a,int k){
    int n=a.size();
    map<int,int> mpp;
    int xr=0;
    mpp[xr]++;
    int cnt=0;
    for(int i=0;i<n;i++){
        xr=xr^a[i];

        int x=xr^k;

        cnt+=mpp[x];

        mpp[xr]++;
    }

    return cnt;
}
int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = func2(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

