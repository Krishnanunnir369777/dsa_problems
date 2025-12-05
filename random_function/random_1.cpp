#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
    vector<int> parent,size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int ultp(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=ultp(parent[node]);
    }
    void JoinBySize(int u,int v){
        int ult_u=ultp(u);
        int ult_v=ultp(v);
        if(ult_u==ult_v){
            return ;
        }
        if(size[ult_v]>size[ult_u]){
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else{
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }
};
// Solution class
class Solution{
public:

    // Function to get the sum of weights of edges in MST
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // To store the edges
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int v=it[0];
                int wt=it[1];
                edges.push_back({wt,{i,v}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int sum=0;
        for(auto it:edges){
            int wt=it.first;
            int v=it.second.first;
            int u=it.second.second;
            if(ds.ultp(v)!=ds.ultp(u)){
                sum+=wt;
                ds.JoinBySize(u,v);
            }

        }
        return sum;

    }
};


int main() {
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 2},
        {2, 3, 3},
        {0, 3, 4}
    };
    
    // Forming the adjacency list from edges
    vector<vector<int>> adj[4];
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    // Creating instance of Solution class
    Solution sol;
    
    /* Function call to get the sum 
    of weights of edges in MST */
    int ans = sol.spanningTree(V, adj);
    
    cout << "The sum of weights of edges in MST is: " << ans;
    
    return 0;
}