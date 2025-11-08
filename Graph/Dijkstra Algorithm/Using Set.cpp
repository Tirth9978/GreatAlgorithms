// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> graph(V);
        for (int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        
        
        set<pair<int,int>> s ;
        vector<int> dist(V,1e9);
        dist[src] = 0;    
        s.insert({dist[src] , src});
        
        while(!s.empty()){
            auto it = *(s.begin());
            
            int node = it.second ;
            int distance = it.first ;
            
            s.erase(it);        
            for (auto x : graph[node]){
                int nextNode = x.first;
                int newDist = x.second ;
                    
    
                if (newDist + distance < dist[nextNode]){
                    if (dist[nextNode] != 1e9){
                        s.erase({dist[nextNode] , nextNode});
                    }
                    dist[nextNode] = newDist + dist[node];
                    s.insert({dist[nextNode] , nextNode});
                }
            }
        
        }
        return dist ; 
    }
};