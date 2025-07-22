#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//recursion
int func(int idx,int w,vector<int>& wt,vector<int>& val){  //2^n
    if(idx==0){
        if(wt[idx]<=w){
            return val[0];
        }
        else{
            return 0;
        }
    }
    int not_pick=func(idx-1,w,wt,val);
    int pick=INT_MIN;
    if(wt[idx]<=w){
        pick=val[ind]+func(idx-1,w-wt[idx],wt,val);
    }
    return max(pick,not_pick);
}



//memoization


int func(int idx,int w,vector<int>& wt,vector<int>& val,vector<vector<int>>& dp){  //2^n
    if(idx==0){
        if(wt[idx]<=w){
            return val[0];
        }
        else{
            return 0;
        }
    }
    if(dp[idx][w]!=-1){
        return dp[idx][w];
    }
    int not_pick=func(idx-1,w,wt,val,dp);
    int pick=INT_MIN;
    if(wt[idx]<=w){
        pick=val[ind]+func(idx-1,w-wt[idx],wt,val,dp);
    }
    return dp[idx][w]=max(pick,not_pick);
}





//tabulation

int func(vector<int> wt,vector<int> val,int n,int maxwt){
    vector<vector<int>> dp(n,vector<int>(maxwt+1,0));
    for(int w=wt[0];w<=maxwt;w++){
        dp[0][w]=val[0];
    }
    for(int idx=1;i<n;i++){
        for(int w=0;w<=maxwt;w++){
            int not_pick=dp[idx-1][w];
            int pick=INT_MIN;
            if(wt[idx]<=w){
                pick=val[idx]+dp[idx-1][w-wt[idx]];
            }
            dp[idx][w]=max(pick,not_pick);
        }
    }
    return dp[n-1][maxwt];
}



//optimised
int func(vector<int> wt,vector<int> val,int n,int maxwt){
    vector<int> prev(maxwt+1,0),curr(maxwt+1,0);
    for(int w=wt[0];w<=maxwt;w++){
        prev[w]=val[0];
    }
    for(int idx=1;i<n;i++){
        for(int w=0;w<=maxwt;w++){
            int not_pick=prev[w];
            int pick=INT_MIN;
            if(wt[idx]<=w){
                pick=val[idx]+prev[w-wt[idx]];
            }
            curr[w]=max(pick,not_pick);
        }
        prev=curr;
    }
    return prev[maxwt];
}



//further optimised


int func(vector<int> wt,vector<int> val,int n,int maxwt){
    vector<int> prev(maxwt+1,0);
    for(int w=wt[0];w<=maxwt;w++){
        prev[w]=val[0];
    }
    for(int idx=1;i<n;i++){
        for(int w=maxwt;w>=0;w--){
            int not_pick=prev[w];
            int pick=INT_MIN;
            if(wt[idx]<=w){
                pick=val[idx]+prev[w-wt[idx]];
            }
            prev[w]=max(pick,not_pick);
        }
        
    }
    return prev[maxwt];
}
