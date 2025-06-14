#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool cycle_detect(int V,vector<int> adj[]){
        
        vector<int> indegree(V,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            cnt++;
            q.pop();

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==V){
            return false;
        }
        return true;

    }
	
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	bool ans = obj.cycle_detect(V, adj);
    cout<<ans;

	

	return 0;
}