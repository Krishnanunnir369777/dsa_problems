#include <iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> func(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }

        }
        return ans;
}



int main(){
    
}