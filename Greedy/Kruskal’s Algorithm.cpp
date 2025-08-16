#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union-Find) with Path Compression
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false; // already connected
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w; // sort by weight
}

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(n);
    int mst_weight = 0;
    vector<Edge> mst_edges;

    for (auto e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.w;
            mst_edges.push_back(e);
        }
    }

    cout << "Edges in MST:\n";
    for (auto e : mst_edges)
        cout << e.u << " - " << e.v << " (" << e.w << ")\n";

    return mst_weight;
}

int main() {
    int n = 4; // number of vertices
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    cout << "Minimum Spanning Tree weight = " << kruskal(n, edges) << "\n";
    return 0;
}
