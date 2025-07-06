//dfs 
class Solution {
public:
    
    int minDepth(TreeNode* root) {  //Time complexity:O(maxdepth)
        if(root==NULL){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }
        if(root->left==nullptr){
            return 1+minDepth(root->right);
        }
        if(root->right==nullptr){
            return 1+minDepth(root->left);
        }
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};



//bfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int min_depth=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            min_depth++;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                if(node->left==nullptr && node->right==nullptr){
                    return min_depth;
                }
            }
        }
        return min_depth;
    }
};