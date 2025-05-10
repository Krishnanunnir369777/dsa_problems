#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int func1(vector<int>& nums, int pos, unordered_map<int, int>& memo) {          //O(n^2)
    int n = nums.size();

    if (pos >= n - 1) return 0;  // Base Case: Already at or beyond the last index

    if (memo.find(pos) != memo.end()) return memo[pos];  // Return memoized result

    int maxJump = nums[pos];  // Max steps you can take from current index
    int minSteps = INT_MAX;   // Initialize with max value

    for (int i = 1; i <= maxJump && pos + i < n; ++i) {
        int steps = func1(nums, pos + i, memo);  // Recursive call
        if (steps != INT_MAX)
            minSteps = min(minSteps, 1 + steps);  // Take 1 jump now + steps from next
    }

    memo[pos] = minSteps;
    return minSteps;
}

int jump(vector<int>& nums) {
    unordered_map<int, int> memo;
    return func1(nums, 0, memo);
}

int func2(vector<int>& nums) {   //O(n)
    int jump=0,r=0,l=0;
    while(r<nums.size()-1){
        int farthest=0;
        for(int i=l;i<=r;i++){
            farthest=max(farthest,nums[i]+i);
        }
        l=r+1;
        r=farthest;
        jump+=1;
    }
    return jump;
}
int main(){
    vector<int> nums={2,3,1,1,4};
    cout<<func2(nums);

}