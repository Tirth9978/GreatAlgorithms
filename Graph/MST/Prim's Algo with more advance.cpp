class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int ,int>>> graph(V);
        for (int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        using pr = pair<int ,pair<int,int>>;
        priority_queue<pr , vector<pr> , greater<pr>> pq;
        vector<bool> visited(V , false );
        int sum =0;
        pq.push({0 , {0,-1}});
        while(!pq.empty()){
            int node = pq.top().second.first ;
            int p = pq.top().second.second ;
            int dis = pq.top().first ;
            
            pq.pop();
            if (visited[node]){
                continue;
            }
            if (dis != -1){
                sum += dis;
            }
            
            
            visited[node] = true;
            
            
            for (auto x: graph[node]){
                if (!visited[x.first]){
                    pq.push({x.second , {x.first , node}});
                }
            }
        }
        return sum ; 
    }
};
