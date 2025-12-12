#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find all subset sums using bitmasking
    vector<int> subsetSums(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        for(int mask=0;mask<(1<<n);mask++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    sum+=arr[i];
                }
            }
            ans.push_back(sum);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr = {1,2,3};
    vector<int> result = sol.subsetSums(arr);

    // Print the subset sums
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}