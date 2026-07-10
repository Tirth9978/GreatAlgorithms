class Solution {
    vector<int> rank , parent;
    
  public:
    void build (int n) {
        rank.resize(n+1 , 0);
        parent.resize(n+1);
        for (int i=0;i<=n;i++) {
            parent[i] = i;
        }
        return ;
    }
    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByrank(int u,int v){
        int ult_u = findParent(u);
        int ult_v =findParent(v);
        if (ult_u == ult_v) return ;
        
        if (rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        }
        else if (rank[ult_u] > rank[ult_v]){
            parent[ult_v] = ult_u;
        }
        else {
            parent[ult_v] = ult_u;
            rank[ult_u] ++;
        }
        return ;
    }
    bool isConnect(int u,int v) {
        return findParent(u) == findParent(v);
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        build(V);

        vector<pair<int , pair<int ,int>>> arr ;
        for (auto x : edges){
            arr.push_back({x[2] , {x[0] , x[1]}});
        }
        // cout << 1 << endl;
        sort(arr.begin(),arr.end());
        
        int sum =0;
        for (auto x : arr){
            int u = x.second.first ;
            int v = x.second.second;
            int w = x.first;
            if (!isConnect(u,v)) {
                sum += w;
                unionByrank(u,v);
            }
        }
        return sum ;
    }
};







