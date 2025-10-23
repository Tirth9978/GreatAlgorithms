class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size() , -1) ;
        queue<int> q;
        q.push(0);
        int color = 0;
        visited[0] = color;
        while(!q.empty()) {
            int node = q.front() ;
            q.pop();
            for (int i=0;i<graph[node].size() ;i++) {
                if (visited[graph[node][i]] == -1) {
                    visited[graph[node][i]] = !visited[node] ;
                    q.push(graph[node][i]);
                }
                else if(visited[graph[node][i]] == visited[node]){
                    return false;
                }
            }
        }
        return true;
    }   
};