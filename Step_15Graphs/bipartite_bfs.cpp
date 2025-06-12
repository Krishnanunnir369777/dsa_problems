class Solution {

public:
    bool check(vector<vector<int>>& graph,vector<int>& color,int start){  //O(n+2*e)
         
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto adjacent:graph[node]){
                if(color[adjacent]==-1){
                    color[adjacent]=!color[node];
                    q.push(adjacent);
                }
                else if(color[adjacent]==color[node]){
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(graph,color,i)==false){
                    return false;
                }
            }
        }
        return true;
        
    }
};