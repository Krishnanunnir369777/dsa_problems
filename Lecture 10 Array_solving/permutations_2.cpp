




class Solution {
public:
    vector<vector<int>> ans;

    void func(vector<int>& nums, int idx, int n) {
        if (idx == n) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;  // Track used elements at this level
        for (int i = idx; i < n; ++i) {
            if (used.count(nums[i])) continue; // Skip duplicates
            used.insert(nums[i]);

            swap(nums[idx], nums[i]);
            func(nums, idx + 1, n);
            swap(nums[idx], nums[i]); // Backtrack
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        func(nums, 0, nums.size());
        return ans;
    }
};
