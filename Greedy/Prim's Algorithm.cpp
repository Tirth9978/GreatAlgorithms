#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P; // (weight, vertex)

int primMST(int n, vector<vector<pair<int,int>>> &adj) {
    vector<bool> inMST(n, false);  // track included vertices
    priority_queue<P, vector<P>, greater<P>> pq; // min-heap
    int mst_weight = 0;

    // Start from vertex 0
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue; // already included
        inMST[u] = true;
        mst_weight += w;

        // Add neighbors
        for (auto [v, weight] : adj[u]) {
            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }

    return mst_weight;
}

int main() {
    int n = 4;
    vector<vector<pair<int,int>>> adj(n);

    // Graph edges (u, v, w)
    vector<tuple<int,int,int>> edges = {
        {0,1,10}, {0,2,6}, {0,3,5}, {1,3,15}, {2,3,4}
    };

    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout << "Minimum Spanning Tree weight = " << primMST(n, adj) << "\n";
}
