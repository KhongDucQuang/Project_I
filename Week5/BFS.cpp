// Description
// Given undirected graph G = (V,E) in which V = {1, 2, ..., n} is the set of nodes, and E is the set of m edges.
// Write a program that computes the sequence of nodes visited using a BFS algorithm (the nodes are considered in a lexicographic order)

// Input
// Line 1: contains 2 integers n and m which are the number of nodes and the number of edges
// Line i+1 (i = 1, ..., m): contains 2 positive integers u and v which are the end points of the ith edge

// Output
// Write the sequence of nodes visited by a BFS procedure (nodes a are separated by a SPACE character)
// Example

// Input
// 6 7
// 2 4
// 1 3
// 3 4
// 5 6
// 1 2
// 3 5
// 2 3

// Output
// 1 2 3 4 5 6
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(vector<vector<int>>& graph, int s, vector<bool>& visited){
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int x : graph[cur]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

void addEdge(vector<vector<int>>& graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int main(){
    
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> my_graph(n+1);
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        addEdge(my_graph, u, v);
    }
    
    for (int i = 1; i <= n; i++) {
        sort(my_graph[i].begin(), my_graph[i].end());
    }

    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(my_graph, i, visited);
        }
    }
    
    return 0;
}
