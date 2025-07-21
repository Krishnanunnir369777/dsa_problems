#include <bits/stdc++.h>
using namespace std;

int func1(vector<int>& arr) {   //O(n^2)
    const long long MOD=1e9+7;
    int sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int mini=arr[i];
        for(int j=i;j<n;j++){
            mini=min(mini,arr[j]);

            sum=(sum+mini)%MOD;
        }
    }
    return sum;
    
}




int sumSubarrayMins(vector<int>& nums) {            //O(5N)
    int length = nums.size();
    vector<int> left(length, -1);
    vector<int> right(length, length);
    stack<int> stk;

    for (int i = 0; i < length; ++i) {  //previous smallest
        while (!stk.empty() && nums[stk.top()] >= nums[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            left[i] = stk.top();
        }
        stk.push(i);
    }

    stk = stack<int>();

    for (int i = length - 1; i >= 0; --i) { // next smallest
        while (!stk.empty() && nums[stk.top()] > nums[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            right[i] = stk.top();
        }
        stk.push(i);
    }

    ll sum = 0;

    for (int i = 0; i < length; ++i) {
        sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
        sum %= MOD;
    }

    return sum;
}



int main(){
    vector<int> arr={3,1,2,4};
    cout<<func1(arr);

}