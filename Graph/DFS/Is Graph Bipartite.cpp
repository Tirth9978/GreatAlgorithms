class Solution {
public:
    bool find = true ;
    void DFS(vector<vector<int>>& graph , vector<int> & color,int index,int nextColor){
        if (color[index] == -1){
            color[index] = nextColor ;

        }
        for (auto x : graph[index]){
            if (color[x] == -1){
                DFS(graph ,color , x , 1-nextColor);
            }
            else if (color[x] == nextColor){
                find = false ;
            }
        }
        return ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for (int i=0;i<color.size();i++) {
            if (color[i] == -1) DFS(graph , color , i , 0);
        }   
        
        if (find) return 1;
        return 0;
    }
};
