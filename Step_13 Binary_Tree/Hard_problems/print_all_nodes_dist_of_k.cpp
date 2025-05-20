








class Solution {
public:
    void func(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track){
        if(root==NULL){
            return ;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
                parent_track[current->left]=current;
            }
            if(current->right){
                q.push(current->right);
                parent_track[current->right]=current;
            }

        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        func(root,parent_track);

        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int n=q.size();
            if(curr_level++>=k){
                break;
            }
            for(int i=0;i<n;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }

        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            ans.push_back(current->val);
        }
        return ans;
    }
};