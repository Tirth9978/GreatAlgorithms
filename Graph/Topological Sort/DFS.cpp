class Solution {
  public:
  
    void DFS(vector<vector<int>> & graph , vector<bool>& visited , int node ,stack<int> & st) {
        visited[node] = 1;
        
        for (auto x : graph[node]) {
            if (!visited[x]){
                DFS(graph , visited , x , st);
            }
        }
        
        st.push(node); 
        return ; 
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph (V);
       
        for (int i= 0 ;i <edges.size() ; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
       
        vector<bool> visited(V , 0);
        stack<int> st;
        vector<int> ans ; 
        
        for (int i=0;i<V;i++) {
            if (!visited[i]){
                DFS(graph , visited , i , st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans ;
    }
};