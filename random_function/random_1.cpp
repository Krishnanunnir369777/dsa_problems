#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool dfs(int node,int parent,vector<int>& vis,vector<int> adj[]){
            vis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it]){
                    dfs(it,node,vis,adj);
                }
                else if(it)
            }
        }
        bool isCycle(int V,vector<int> adj[]){
            vector<int> vis(V,0);
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    if(dfs(i,-1,vis,adj)){
                    return true;
                }
                }
            }
            return false;
        }

};

int main(){
    int V=5;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1); 

    Solution sol;
    if (sol.isCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle found\n";

    return 0;
}