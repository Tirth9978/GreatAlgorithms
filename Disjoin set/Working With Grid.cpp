class DisJoinSet{
    vector<int> size , parent;

public :
    DisJoinSet(int n) {
        size.resize(n , 1);
        parent.resize(n);
        for (int i=0;i<n;i++){
            parent[i] = i;
        }

    }
    int findParent(int node){
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u,int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return ;
        if (size[pu] > size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return ;
    }

    bool isConnected(int u,int v) {
        return findParent(u) == findParent(v);
    }

    int getsize(int node) {
        return size[node];
    }
};

class Solution {
public:
    bool isValid(int i,int j,int n ,int m){
        return i>=0 && i < n && j >=0 && j < m;
    }
    int largestIsland(vector<vector<int>>& grid) {
        DisJoinSet ds(grid.size() * grid[0].size());
        for (int i=0;i<grid.size() ;i ++){
            for (int j=0;j<grid[0].size();j++)  {
                if (grid[i][j] == 0) continue;
                int forI[]= {-1,0,1,0};
                int forJ[] = {0,1,0,-1};
                for (int k=0;k<4;k++){
                    int newI = forI[k] + i;
                    int newJ = forJ[k] + j;
                    if (isValid(newI,newJ,grid.size(),grid[0].size())) {
                        if (grid[newI][newJ] == 1) {
                            int node1 = i * (grid.size()) + j;
                            int node2 = newI * (grid.size()) + newJ;
                            ds.unionBySize(node1 , node2);
                        }
                    }
                }
            }
        }
        int ans =0;
        for (int i=0;i<grid.size() ;i ++){
            for (int j=0;j<grid[0].size() ;j++){
                if (grid[i][j] == 1) continue;
                int forI[]= {-1,0,1,0};
                int forJ[] = {0,1,0,-1};
                set<int> ref;
                for (int k=0;k<4;k++){
                    int newI = forI[k] + i;
                    int newJ = forJ[k] + j;
                    if (isValid(newI,newJ,grid.size(),grid[0].size())) {
                        if (grid[newI][newJ] == 1) {
                            ref.insert(ds.findParent(newI * grid.size() + newJ));
                        }
                    }
                }
                int total = 1;
                for (auto x: ref){
                    total +=ds.getsize(x);
                }
                ans = max(ans , total);
            }
        }
        for (int i=0;i<grid.size() ;i ++){
            for (int j=0;j<grid[0].size() ;j++){
                ans = max(ans , ds.getsize(ds.findParent(i * grid.size() + j)));
            }
        }
        return ans;
    }
};



