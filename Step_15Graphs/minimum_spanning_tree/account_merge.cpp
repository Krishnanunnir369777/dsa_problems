class DisjointSet{
    public:
    vector<int> rank;
    vector<int> parent;
    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int ult_p(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=ult_p(parent[node]);
    }
    void union_by_rank(int u,int v){
        int ult_u=ult_p(u);
        int ult_v=ult_p(v);
        if(ult_u==ult_v){
            return ;
        }
        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u]=ult_v;
        }
        else if(rank[ult_v]<rank[ult_u]){
            parent[ult_v]=ult_u;
        }
        else{
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) { //Time Complexity: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E))
        int n=accounts.size();
        unordered_map<string,int> mapMailNode;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mapMailNode.find(accounts[i][j])==mapMailNode.end()){
                    mapMailNode[accounts[i][j]]=i;
                }
                else{
                    ds.union_by_rank(i,mapMailNode[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> mergedMail(n);
        for(auto it:mapMailNode){
            string mail=it.first;
            int node=ds.ult_p(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0){
                continue;
            }
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};