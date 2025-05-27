


class Solution {
public:
    void func(int curr,int& maxi,TreeNode* root){
        if(root==NULL){
            maxi=max(curr,maxi);
            return ;
        }
        func(curr+1,maxi,root->left);
        func(curr+1,maxi,root->right);
    }
    int maxDepth(TreeNode* root) {
        int maxi=0;
        int curr=0;
        func(curr,maxi,root);

        return maxi;
    }
};