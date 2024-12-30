#include <iostream>
using namespace std;
#include <bits/stdc++.h>




int func1(vector<int> arr, int n, int x) { //Time Complexity: O(N)
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            // lower bound found:
            return i;
        }
    }
    return n;
}

int func2(vector<int> arr,int n,int x){
    int s=0;
    int e=n-1;
    int ans=n;
    while(s<=e){
        int mid=(s+e)/2;
        // maybe an answer
        if(arr[mid]>=x){
            ans=mid;
            //look for smaller index on the left
            e=mid-1;
        }
        else{
            s=mid+1;
        }

    }
    return ans;
} 

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = func2(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}