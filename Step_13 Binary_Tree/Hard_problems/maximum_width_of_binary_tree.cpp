                            
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
    // Function widthOfBinaryTree to find the 
    // maximum width of the Binary Tree
    int widthOfBinaryTree(TreeNode* root) {
    int ans = 0;
    if (root == NULL) return ans;

    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        int n = q.size();
        unsigned long long mini = q.front().second;  // to normalize indices
        unsigned long long first = 0, last = 0;

        for (int i = 0; i < n; i++) {
            unsigned long long curr_id = q.front().second - mini;
            TreeNode* node = q.front().first;
            q.pop();

            if (i == 0) first = curr_id;
            if (i == n - 1) last = curr_id;

            if (node->left) {
                q.push({node->left, 2 * curr_id + 1});
            }
            if (node->right) {
                q.push({node->right, 2 * curr_id + 2});
            }
        }
        ans = max(ans, static_cast<int>(last - first + 1));
    }

    return ans;
}

};


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    int maxWidth = sol.widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: "
                        << maxWidth << endl;

    return 0;
}
                            
                        