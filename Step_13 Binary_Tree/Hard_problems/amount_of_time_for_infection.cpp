

// similar to print all nodes dist of k problem


class Solution {
public:
    int timef(TreeNode* target,unordered_map<TreeNode*,TreeNode*>& parents){
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int fl=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    fl=1;
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    fl=1;
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parents[node] && !visited[parents[node]]){
                    fl=1;
                    q.push(parents[node]);
                    visited[parents[node]]=true;
                }
            }
            if(fl){
                ans++;
            }
        }
        return ans;

    }
    TreeNode* func(TreeNode* root,int start,unordered_map<TreeNode*,TreeNode*>& parents){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* current=q.front();
            if(current->val==start){
                res=current;
            }
            q.pop();
            if(current->left){
                q.push(current->left);
                parents[current->left]=current;
            }
            if(current->right){
                q.push(current->right);
                parents[current->right]=current;
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parents;
        TreeNode* target=func(root,start,parents);
        int maxi=timef(target,parents);

        return maxi;
    }
};