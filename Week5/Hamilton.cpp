// Description
// Given an undirected graph G = (V,E). Write a program to check if G is a Hamiltonian graph.
// Input
// Line 1: a positive integer T (number of graphs)
// Subsequent lines are information about T graphs, each has the following format:
// Line 1: n and m (number of nodes and edges)
// Line i+1 (i = 1, 2, ..., m): u and v : two end points of the ith edge
// Output
// In the i
// th
//  line, write 1 if the corresponding is a Hamiltonian graph, and write 0, otherwise
// Example
// Input
// 2
// 5 5
// 1 2
// 1 3
// 2 4
// 2 5
// 3 5
// 7 13
// 1 3
// 1 5
// 1 7
// 2 4
// 2 5
// 2 6
// 3 4
// 3 5 
// 3 7
// 4 6
// 4 7
// 5 7
// 6 7

// Output
// 0
// 1
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T; cin >> T;
    while(T > 0){
        int n, m; cin >> n >> m;
        vector<int> Degree(n+1, 0);
        for(int i = 1; i <= m; i++){
            int u, v; cin >> u >> v;
            Degree[u]++;
            Degree[v]++;
        }
        int i = 1;
        for(i ; i <= n; i++){
            if(Degree[i] < n/2){
                cout << 0 << endl;
                break;
            }
        }
        if(i == n+1) cout << 1;
        T--;
    }
    return 0;
}