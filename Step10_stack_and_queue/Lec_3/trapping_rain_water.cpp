#include <iostream>
using namespace std;
#include <bits/stdc++.h>


int func1(vector<int>& height) {  //Time Complexity: O(N*N) 
    int ans=0;
    int n=height.size();
    for(int i=0;i<n;i++){
        int rightMax=0,leftMax=0;
        int j=i;
        while(j>=0){
            leftMax=max(leftMax,height[j]);
            j--;
        }
        j=i;
        while(j<n){
            rightMax=max(rightMax,height[j]);
            j++;
        }
        ans+=min(leftMax,rightMax)-height[i];
    }
    return ans;
}

int func2(vector<int>& height) {  //O(n)

    int n=height.size();
    int prefix[n],suffix[n];
    prefix[0]=height[0];

    for(int i=1;i<n;i++){
        prefix[i]=max(prefix[i-1],height[i]);
    }

    suffix[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=max(suffix[i+1],height[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=min(prefix[i],suffix[i])-height[i];
    }
    return ans;
}

//optimised

int func3(vector<int>& height) {  //space com O(1)  &&  time com O(n)
    int left=0;
    int n=height.size();
    int right=n-1;
    int leftMax=height[left];
    int rightMax=height[right];
    int ans=0;
    while(left<right){
        if(leftMax<rightMax){
            left++;
            leftMax=max(leftMax,height[left]);
            ans+=leftMax-height[left];
        }
        else{
            right--;
            rightMax=max(rightMax,height[right]);
            ans+=rightMax-height[right];
        }
    }
    return ans;
}
int main(){
    vector<int> arr={6,5,3,1};
    cout<<func1(arr);

}