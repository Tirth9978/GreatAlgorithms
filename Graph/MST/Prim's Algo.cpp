class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(V);
        for (auto x : edges) {
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
        q.push({0,0});
        
        vector<bool> visited(V , false);
        int sum = 0;
        
        while (!q.empty()) {
            pair<int,int> p = q.top();
            q.pop();
            
            int w = p.first ;
            int node = p.second ;
            
            if (!visited[node]) {
                visited[node] = 1;
                sum += w;
            }
            
            for (auto x : graph[node]) {
                if (!visited[x.first]) {
                    q.push({x.second , x.first});
                }
            }
        }
        return sum ;
    }
};