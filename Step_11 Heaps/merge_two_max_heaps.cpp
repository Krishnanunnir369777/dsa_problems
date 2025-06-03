
// brute          //O(n)
class Solution{                              //Time Complexity: O((n + m) * log(n + m))
    public:
        vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
       priority_queue <int> pq;
       for(int i=0; i<n; i++)
       {
           pq.push(a[i]);
       }
       for(int i=0; i<m; i++)
       {
           pq.push(b[i]);
       }
       vector<int>v;
       while(!pq.empty())
       {
           v.push_back(pq.top());
           pq.pop();
       }
       return v;
   }
};

