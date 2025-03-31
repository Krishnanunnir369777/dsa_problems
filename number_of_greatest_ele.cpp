#include <bits/stdc++.h>
using namespace std;


vector<int> func1(vector<int>& arr,int q,vector<int>& indices){
    vector<int> ans(q);
    int n=arr.size();
    for(int i=0;i<q;i++){
        int curr=arr[indices[i]];
        int r=n-1;
        stack<int> st;
        while(r>indices[i]){
            if(arr[r]>curr){
                st.push(arr[r]);
            }
            r--;
        }
        ans[i]=st.size();
    }
    return ans;

}

int main(){
    vector<int> arr={3, 4, 2, 7, 5, 8, 10, 6};
    int q=2;
    vector<int> indices={0,5};
    vector<int> ans=func1(arr,q,indices);
    for(auto it:ans){
        cout<<it<<" ";
    }
}