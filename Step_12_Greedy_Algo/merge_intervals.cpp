#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> func(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1 || n==0){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int>& last=ans.back();   // note this important we are using & 
            if(intervals[i][0]<=last[1]){
                last[1]=max(last[1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
        
}
int main(){
    
}