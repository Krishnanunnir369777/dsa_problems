#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int func1(vector<int>& arr){ //Time Complexity: O(NlogN) + O(N)
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int maxi=INT_MIN;
    int length=1;
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    for(int i=1;i<n;i++){
        
        if(abs(arr[i]-arr[i-1]) ==1){
            length++;
        }
        else{
            length=1;
        }
        maxi=max(maxi,length);
    }
    return maxi;
}
int func2(vector<int> & arr){
    int n=arr.size();
    if(n==0) return 0;

    int longest=1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it:st){

        if(st.find(it-1)==st.end()){
            
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt++;
            }
            longest=max(longest,cnt);
        }
    }
    return longest;

}

int main(){
    vector<int> arr={100, 200, 1, 3, 2, 4};
    cout<<func2(arr);
}
