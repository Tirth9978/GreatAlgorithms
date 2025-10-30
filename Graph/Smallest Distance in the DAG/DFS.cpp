// User function Template for C++
class Solution {
  public:
    
    void DFS(vector<vector<pair<int ,int>>> & graph ,stack<int> & st , vector<bool> & visited,int node) {
        visited[node] = 1;
        
        for (auto x : graph[node]) {
            if (!visited[x.first]){
                DFS(graph , st , visited , x.first);
            }
        }
        
        st.push(node);
        return ;
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int ,int>>> graph(V);
        
        for (int i = 0 ;i <edges.size() ;i ++) {
            graph[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
        }
        
        stack<int> st;
        vector<bool> visited(V , false);
        
        for (int i =0 ;i <V ;i ++){
            if (!visited[i]){
                DFS(graph  , st , visited , i);
            }
        }
        
        vector<int> dist(V , INT_MAX);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for (auto x : graph[node]){
                int a = x.first  ;
                int w = x.second ;
                if (dist[node] + w < dist[a]){
                    dist[a] = dist[node] + w;
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};
