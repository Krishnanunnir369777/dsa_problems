class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return func(preorder,0,preorder.size()-1);
    }
    TreeNode* func(vector<int>& preorder,int start,int end){
        if(start>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[start]);
        int i=start+1;
        while(i<=end && preorder[i]<root->val){
            i++;
        }
        root->left=func(preorder,start+1,i-1);
        root->right=func(preorder,i,end);


        return root;
    }
};





class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return func(preorder,i,INT_MAX);        
    }
    TreeNode* func(vector<int>& preorder,int& i,int bound){
        if(i==preorder.size() || preorder[i]>bound){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[i++]);
        root->left=func(preorder,i,root->val);
        root->right=func(preorder,i,bound);

        return root;
    }
};