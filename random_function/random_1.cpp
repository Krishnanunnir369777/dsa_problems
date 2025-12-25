#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Solve function using recursion with memoization
    // ind -> current index the frog needs to reach
    // height -> vector of heights
    // dp -> memo table where dp[i] stores min cost to reach i
    

    // Helper to handle edge cases and start recursion
    int frogJump(const vector<int>& height) {
        // Handle empty input
        int n=height.size();
        int prev2=0,prev1=0;
        dp[0]=0;
        for(int i=1;i<n;i++){
            int one_jump=prev1+abs(height[i]-height[i-1]);
            int two_jump=INT_MAX;
            if(i>1){
                two_jump=prev2+abs(height[i]-height[i-2]);
            }
            dp[i]=min(one_jump,two_jump);
        }
        return dp[n-1];
    }
};

int main() {
    // Define the heights array
    vector<int> height{30, 10, 60, 10, 60, 50};

    // Create Solution instance
    Solution sol;

    // Compute and print the minimum energy
    cout << sol.frogJump(height) << endl; // Expected: 40

    return 0;
}