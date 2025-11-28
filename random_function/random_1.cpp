#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> dijkstra(int V,vector<vector<pair<int,int>>>& adj,int src){
        vector<int> dist(V,1e9);
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
                if(dist[node]+wt<dist[next]){
                    dist[next]=dist[node]+wt;
                    pq.push({dist[next],next});
                }
            }
        }
        return dist;

    }
};

int main(){
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

    Solution obj;
    vector<int> ans=obj.dijkstra(V,adj,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}