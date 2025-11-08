// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> graph(V);
        for (int i=0;i<edges.size();i++) {
            graph[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int ,int>>> q;
        vector<int> dist(V , 10e9);
        
        dist[src] = 0;
        q.push({dist[src] , src});
        while(!q.empty()){
            int distance = q.top().first ;
            int node = q.top().second ;
            q.pop();
            
            for (auto x : graph[node]){
                int weight = x.second ; 
                int nextNode = x.first ;
                
                if (weight + distance < dist[nextNode]) {
                     dist[nextNode] = weight + distance ; 
                     q.push({dist[nextNode] , nextNode});
                }
            }
        }
        return dist;
    }
};
