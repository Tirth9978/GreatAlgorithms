#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;  // {distance, node}

void dijkstra(int V, vector<vector<pii>>& graph, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue; // Skip outdated entry

        for (auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << dist[i] << "\n";
    }
}

int main() {
    int V = 4; // number of nodes
    vector<vector<pii>> graph(V);

    // Graph (same as example above)
    graph[0].push_back({1, 2}); // A-B (2)
    graph[1].push_back({0, 2});

    graph[0].push_back({2, 1}); // A-C (1)
    graph[2].push_back({0, 1});

    graph[0].push_back({3, 4}); // A-D (4)
    graph[3].push_back({0, 4});

    graph[1].push_back({3, 7}); // B-D (7)
    graph[3].push_back({1, 7});

    graph[2].push_back({3, 3}); // C-D (3)
    graph[3].push_back({2, 3});

    dijkstra(V, graph, 0); // Source = A (0)

    return 0;
}
