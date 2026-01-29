class Solution {
public:

    vector<vector<long long>> floyd(vector<vector<pair<int,int>> >& graph) {
        vector<vector<long long >> ans(26,vector<long long > (26,1e9)) ;
        for(int i=0;i<26;i++){
            ans[i][i] = 0;
        } 
        for (int i=0;i<graph.size();i++){
            for(auto x : graph[i]){
                int u = i;
                int v = x.first;
                int w = x.second;
                ans[u][v] = min((long long )w,ans[u][v]);
            }
        }

        for(int k = 0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j = 0;j<26;j++){
                    if (ans[i][k] != 1e9 && ans[k][j] != 1e9){
                        ans[i][j] = min(ans[i][j] , ans[i][k] + ans[k][j]);
                    }
                }
            }
        }
        return ans;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if (source.size() != target.size()){
            return -1;
        }

        vector<vector<pair<int,int>>> graph(26);
        for(int i=0;i<original.size();i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int w  = cost[i];
            graph[u].push_back({v,w});
        }

        vector<vector<long long >> distance = floyd(graph);
        long long int total = 0;
        for(int i=0;i<source.size();i++){
            if (source[i] != target[i]){
                int u = (int)(source[i] -'a');
                int v = (int)(target[i]-'a');
                if (distance[u][v] == 1e9){
                    return -1;
                }
                total += distance[u][v];
            }
        }
        return total ;
    }
};