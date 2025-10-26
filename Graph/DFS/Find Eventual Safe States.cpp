class Solution {
public:

    bool DFS(vector<vector<int>>& graph , vector<bool> & visited , vector<bool> & path ,vector<bool> & check ,int node) {
        visited[node] = 1 ; 
        path[node] = 1;

        for (auto x : graph[node]) {
            if (!visited[x]) {
                if (DFS(graph , visited , path , check , x))  return 1;
            }
            else if (path[x]) return true ;  
        }

        check[node] = 1;
        path[node] = 0;

        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size() , false);
        vector<bool> path(graph.size() , false);
        vector<bool> check(graph.size() , false);

        vector<int> ans ; 

        for (int i=0;i<graph.size() ;i ++) {
            if (!visited[i]) {
                DFS(graph , visited , path , check , i);
            }
        }

        for (int i =0 ;i<graph.size() ; i++){
            if (check[i]) {
                ans.push_back(i);
            }
        }
        return ans ; 
    }
};