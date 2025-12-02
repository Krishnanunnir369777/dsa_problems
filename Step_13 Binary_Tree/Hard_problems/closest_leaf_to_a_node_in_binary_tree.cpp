#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to create parent mapping and find pointer to node x
TreeNode* markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int x) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* target = NULL;

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr->val == x) {
            target = curr;
        }

        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
    return target;
}

int closestLeafDistance(TreeNode* root, int x) {
    if (!root) return -1;

    unordered_map<TreeNode*, TreeNode*> parent;   // Track parents
    TreeNode* target = markParents(root, parent, x);

    if (!target) return -1;   // x not found

    queue<pair<TreeNode*, int>> q;   // BFS from node x
    unordered_set<TreeNode*> visited;

    q.push({target, 0});
    visited.insert(target);

    while (!q.empty()) {
        auto [curr, dist] = q.front();
        q.pop();

        // If leaf found → return distance
        if (!curr->left && !curr->right) {
            return dist;
        }

        // Explore left
        if (curr->left && !visited.count(curr->left)) {
            visited.insert(curr->left);
            q.push({curr->left, dist + 1});
        }
        // Explore right
        if (curr->right && !visited.count(curr->right)) {
            visited.insert(curr->right);
            q.push({curr->right, dist + 1});
        }
        // Explore parent
        if (parent.count(curr) && !visited.count(parent[curr])) {
            visited.insert(parent[curr]);
            q.push({parent[curr], dist + 1});
        }
    }
    return -1;
}
