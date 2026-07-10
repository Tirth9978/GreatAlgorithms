#include<iostream>
#include<vector>
using namespace std ;

class DisjoinSet {
    vector<int> rank ;
    vector<int> parent;
    vector<int> size;

public: 
    DisjoinSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i=0;i<=n;i++) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if (ult_u == ult_v) return ;

        if (rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        }
        else if (rank[ult_v] < rank[ult_u]){
            parent[ult_v] = ult_u;
        }
        else {
            parent[ult_v] = ult_u;
            rank[ult_u] ++ ;
        }
        return ;
    }

    void unionBySize(int u,int v) {
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if (ult_u == ult_v) return ;

        if (size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }

    int countCompoentent() {
        int count =0;
        for (int i=0;i<=n;i++) {
            if (parent[i] == i){
                count ++ ;
            }
        }
        return count ;
    }

    bool isConnect(int u,int v){
        if (findParent(u) == findParent(v)) return 1;
        return 0;
    }
};

int main(){
    DisjoinSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    if (ds.isConnect(1,5)){
        cout << "Yes 1 and 5 are connect\n";
    }else cout << "No 1 and 5 are not connect\n";

    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    ds.unionByRank(3,7);
    if (ds.isConnect(1,5)){
        cout << "Yes 1 and 5 are connect\n";
    }else cout << "No 1 and 5 are not connect\n";
    return 0;
}
