#include <bits/stdc++.h>
using namespace std;


long long func1(vector<int>& nums) {
    long long range=0;
    int n=nums.size();
    for(int i=0;i<n;i++){     //O(n^2)
        int mini=nums[i];
        int maxi=nums[i];
        for(int j=i;j<n;j++){
            mini=min(mini,nums[j]);
            maxi=max(maxi,nums[j]);
            range+=maxi-mini;
        }
    }
    return range;
    
}



long long sum_min(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> left(n, -1), right(n, n);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right[i] = st.top();
        }
        st.push(i);
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += static_cast<long long>(i - left[i]) * (right[i] - i) * nums[i];
        
    }
    return sum;
}

long long sum_max(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> left(n, -1), right(n, n);

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right[i] = st.top();
        }
        st.push(i);
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += static_cast<long long>(i - left[i]) * (right[i] - i) * nums[i];
        
    }
    return sum;
}

long long func2(vector<int>& nums) {
    return sum_max(nums) - sum_min(nums) ;
}




int main(){

    vector<int> nums={1,2,3};
    cout<<func1(nums);
}

