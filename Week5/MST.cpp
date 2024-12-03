// Description
// Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v)∈E(u,v)∈E has weight w(u,v)w(u,v). Compute minimum spanning tree of G.
// Input
// Line 1: N and M (1≤N,M≤10
// 5
// ) in which NN is the number of nodes and MM is the number of edges.
// Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)
// Output
// Write the weight of the minimum spanning tree found.
// Example
// Input
// 5 8
// 1 2 1
// 1 3 4
// 1 5 1
// 2 4 2
// 2 5 1
// 3 4 3
// 3 5 3
// 4 5 2
// Output
// 7
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


int find(int u, vector<int>& parent) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u], parent); 
}


void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = find(u, parent);
    int rootV = find(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int main() {
    int n, m; 
    cin >> n >> m;
    
    vector<pair<pair<int, int>, int>> listEdge;
    for (int i = 0; i < m; i++) {
        int u, v, w; 
        cin >> u >> v >> w;
        listEdge.push_back({{u, v}, w});
    }

    sort(listEdge.begin(), listEdge.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i; 
    }

    int res = 0;  
    int edgesUsed = 0;  

    for (auto& edge : listEdge) {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;

        if (find(u, parent) != find(v, parent)) {
            unionSets(u, v, parent, rank);
            res += w;
            edgesUsed++;
            if (edgesUsed == n - 1) break;
        }
    }

    cout << res;
    return 0;
}
