#include <bits/stdc++.h>
using namespace std;

class Solution {
public:  
    // Function to implement Dijkstra's Algorithm
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int> dist(V,1e9),parent(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            if(dis>dist[node]){
                continue;
            }
            for(auto it:adj[node]){
                int next=it.first;
                int wt=it.second;
                if(wt+dist[node]<dist[next]){
                dist[next]=wt+dist[node];
                pq.push({dist[next],next});
                parent[next]=node;
            }
            }
        }
        vector<int> path;
        int node=V-1;
        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(0);
        reverse(path.begin(),path.end());
        return path;

        
    }
};

int main() {
    // Number of vertices
    int V = 5;

    // Adjacency list {neighbor, weight}
    vector<vector<pair<int,int>>> adj(V);

    // Example edges
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 2});

    // Run algorithm
    Solution obj;
    vector<int> path = obj.dijkstra(V, adj, 0);

    // Print shortest distances
    for (int i = 0; i < path.size(); i++) {
        cout << path[i]<<" ";
    }
}

