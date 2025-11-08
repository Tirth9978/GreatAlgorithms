class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for (int i=0;i<edges.size();i++) {  
            graph[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
        
        vector<int> dist(graph.size()   , 1e9);
        vector<int> parent(graph.size());
        for(int i=0;i<graph.size();i++)parent[i] = i;
        
        dist[1] = 0;
        q.push({0 , 1});
        while(!q.empty()) {
            int node = q.top().second;
            int distance = q.top().first;
            q.pop();
            
            for (auto x : graph[node]) {
                int nextNode = x.first ;
                int newDist = x.second ;
                
                if (newDist + distance < dist[nextNode]) {
                    dist[nextNode] = newDist + distance ;
                    q.push({dist[nextNode], nextNode}) ; 
                    parent[nextNode] = node ;
                }
            }
        }
            
        if (dist[n] == 1e9) {
            return {-1};
        }
        vector<int> ans ;
        int node = n ;
        
        while(parent[node] != node) {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};