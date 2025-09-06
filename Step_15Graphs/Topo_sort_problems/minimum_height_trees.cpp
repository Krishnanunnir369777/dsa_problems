class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Single node case
        
        // Step 1: Build adjacency list and degree array
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        // Step 2: Push all initial leaves into queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        // Step 3: Iteratively trim leaves until <= 2 nodes left
        int remaining = n;
        while (remaining > 2) {
            int leavesCount = q.size();
            remaining -= leavesCount; // Remove current leaves
            
            for (int i = 0; i < leavesCount; i++) {
                int leaf = q.front();
                q.pop();
                
                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor); // Becomes new leaf
                    }
                }
            }
        }
        
        // Step 4: The remaining nodes are centroids
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
