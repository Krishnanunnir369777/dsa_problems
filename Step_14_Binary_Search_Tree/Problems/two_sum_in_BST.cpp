




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return func(root,k,seen);
    }
    bool func(TreeNode* root,int k,unordered_set<int>& seen){
        if(root==NULL){
            return false;
        }
        if(seen.count(k-root->val))return true;
        seen.insert(root->val);
        return func(root->left,k,seen) || func(root->right,k,seen);
    }

};