#include <bits/stdc++.h>
using namespace std;

class Solution {
public:        // using floyd algorithm
	int findCity(int n, int m, vector<vector<int>>& edges,    // //Time Complexity: O(V3),
	             int distanceThreshold) {
		vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
		for (auto it : edges) {
			dist[it[0]][it[1]] = it[2];
			dist[it[1]][it[0]] = it[2];
		}
		for (int i = 0; i < n; i++) dist[i][i] = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
						continue;
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int cntCity = n;
		int cityNo = -1;
		for (int city = 0; city < n; city++) {
			int cnt = 0;
			for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntCity) {
				cntCity = cnt;
				cityNo = city;
			}
		}
		return cityNo;

	}
};


int main() {

	int n = 4;
	int m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	Solution obj;
	int cityNo = obj.findCity(n, m, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;

	return 0;
}






// using dijkstras algo
// O(n * (n + m) log n)

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int city_num=-1;
        int cnt_city=n;
        for(int i=0;i<n;i++){
            pq.push({0,i});
            vector<int> dist(n,INT_MAX);
            dist[i]=0;
            while(!pq.empty()){
                
                int node=pq.top().second;
                int dis=pq.top().first;
                pq.pop();
                for(auto it:adj[node]){
                    int adj_node=it.first;
                    int wt=it.second;
                    if(dis+wt<dist[adj_node]){
                        dist[adj_node]=dis+wt;
                        pq.push({dist[adj_node],adj_node});
                    }
                }
            }
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=cnt_city){
                cnt_city=cnt;
                city_num=i;
            }
        }
        return city_num;
        
    }
};