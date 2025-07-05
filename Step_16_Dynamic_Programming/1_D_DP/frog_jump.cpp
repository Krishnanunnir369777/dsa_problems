#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// recursion

int f(int idx,vector<int>& heights){
    if(idx==0){
        return 0;
    }
    int left=f(idx-1,heights)+abs(heights[idx]-heights[idx-1]);
    int right=INT_MAX;
    if(idx>1){
        right=f(idx-2,heights)+abs(heights[idx]-heights[idx-2]);
    }

    return min(left,right);
}
int FrogJump(int n,vector<int>& heights){
    return f(n-1,heights);
}






int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}
int main() {  //Time Complexity: O(N)

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  vector<int> dp(n,-1);
  cout<<solve(n-1,height,dp);
}







//tabulation
int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];
}





//optimised

int main(){
    vector<int> height={30,10,60,10,60,50};
    int n=height.size();
    int prev2=0;
    int prev1=0;
    for(int i=1;i<n;i++){
        int jump2=INT_MAX;
        int jump1=prev1+abs(height[i]-height[i-1]);
        if(i>1){
            jump2=prev2+abs(height[i]-height[i-2]);
        }
        int curr=min(jump2,jump1);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;

}
