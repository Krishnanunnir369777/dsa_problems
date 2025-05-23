class Solution {
public:
   bool func(TreeNode* root,long minval,long maxval){
    if(root==NULL){
        return true;
    }
    if(root->val<=minval || root->val>=maxval){
        return false;
    }

    return func(root->left,minval,root->val) && func(root->right,root->val,maxval);
   }
    bool isValidBST(TreeNode* root) {
        return func(root,LONG_MIN,LONG_MAX);
    }
};