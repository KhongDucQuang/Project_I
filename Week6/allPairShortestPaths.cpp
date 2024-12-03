// Description
// Given a directed graph G = (V, E) in which V = {1, 2, ..., n} is the set of nodes, and w(u,v) is the weight (length) of the arc(u,v). Compute d(u,v) - the length of the shortest path from u to v in G, for all u,v in V.
// Input
// Line 1: contains 2 positive integers n and m (1 <= n,m <= 10000)
// Line i+1 (i = 1, 2, ..., m): contains 3 positive integers u, v, w in which w is the weight of the arc (u,v) (1 <= w <= 1000)
// Output
// Line i (i = 1, 2, ..., n): wirte the ith row of the matrix d (if there is not any path from node i to node j, then d(i,j) = -1)
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;

void floyWarshall(int n, vector<vector<int>>& dist){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++){
        dist[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dist[u][v] = min(dist[u][v], w);
    }
    floyWarshall(n, dist);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] == INF){
                cout << -1 << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
