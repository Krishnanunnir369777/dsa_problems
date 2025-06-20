#include <bits/stdc++.h>
using namespace std;


vector<int> shortestPath(int n,int m,vector<vector<int>>& edges){    //Elog(V)
    vector<pair<int,int>> adj[n+1];

    for(auto it:edges){
        adj[0].push_back({adj[1],adj[2]});
        adj[1].push_back({adj[0],adj[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int>dist (n+1,1e9) ,parent(n+1);
    dist[1]=0;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    pq.push({0,1});

    while(!pq.empty()){
        auto it=pq.top();
        int node=it[1];
        int dis=it[0];
        pq.pop();

        for(auto it:adj[node]){
            int adjwt=it[1];
            int adjnode=it[0];
            if(adjwt+dis<dis[adjnode]){
                dist[adjnode]=dis+adjwt;
                pq.push({dist[adjnode],adjnode});
                parent[adjnode]=node;
            }
        }
    }
    if(dist[n]==1e9){
        return {-1};
    }
    vector<int> path;
    int node=n;
    while(parent[node]!=node){
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());

    return path;


}