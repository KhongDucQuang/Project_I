// Description
// Given a directed graph G = (V,E) in which V = {1,2,...,n) is the set of nodes. Each arc (u,v) has a non-negative weight w(u,v). Given two nodes s and t of G. Find the shortest path from s to t on G.
// Input
// Line 1: contains two integers n and m which are the number of nodes and the number of arcs of G (1 <= n <= 100000)
// Line i + 1(i = 1,2,...,m): contains 3 integers u, v, w in which w is the weight of arc(u,v) (0 <= w <= 100000)
// Line m+2: contains two integers s and t
// Output
// Write the weight of the shortest path found or write -1 if no path from s to t was found
// Example
// Input
// 5 7
// 2 5 87
// 1 2 97
// 4 5 78
// 3 1 72
// 1 4 19
// 2 3 63
// 5 1 18
// 1 5

// Output
// 97
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int dijkstra(int n, int s, int t, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return (dist[t] == INF) ? -1 : dist[t];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }

    int s, t;
    cin >> s >> t;
    s--; t--;

    int shortest_path = dijkstra(n, s, t, adj);
    cout << shortest_path << endl;

    return 0;
}
