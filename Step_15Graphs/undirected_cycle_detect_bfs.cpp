class Solution {
  public:
    bool bfs(int src,int vis[],vector<vector<int>>& adj){
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjacentnode:adj[node]){
                if(!vis[adjacentnode]){
                    vis[adjacentnode]=1;
                    q.push({adjacentnode,node});
                }
                else if(parent!=adjacentnode){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {     //Time Complexity: O(N + 2E) + O(N)
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,vis,adj)){
                    return true;
                }
            }
        }
        return false;
        
    }
};