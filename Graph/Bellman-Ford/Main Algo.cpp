// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V , 1e8);
        dist[src] = 0;
        for (int i =0;i<V-1 ;i ++) {
            for (auto x :edges ) {
                int u = x[0];
                int v = x[1];
                int w  = x[2];
                
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v]= dist[u] + w;
                }
            }   
        }
        
        for (auto x : edges){
            int u = x[0];
            int v = x[1];
            int w  = x[2];
                
            if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                return {-1};
            }
        }
        return dist ;
        
    }
};
