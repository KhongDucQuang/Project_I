// Description
// Given a network G = (V, E) which is a directed weighted graph. Node s is the source and node t is the target. c(u,v) is the capacity of the arc (u,v). Find the maximum flow on G.
// Input
// •Line 1: two positive integers N and M (1 <= N <= 10
// 4
// , 1 <= M <= 10
// 6
// )
// •Line 2: contains 2 positive integers s and t
// •Line i+2 (I = 1,. . ., M): contains two positive integers u and v which are endpoints of i
// th
//  arc
// Output
//   Write the value of the max-flow found
// Example
// Input
// 7 12
// 6 7
// 1 7 7
// 2 3 6
// 2 5 6
// 3 1 6
// 3 7 11
// 4 1 7
// 4 2 4
// 4 5 5
// 5 1 4
// 5 3 4
// 6 2 8
// 6 4 10
// Output
// 17

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

const int MAXN = 1000;
int capacity[MAXN][MAXN]; 

int bfs(int s, int t, vector<int>& parent, int n) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2; 
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int v = 0; v < n; v++) {
            if (parent[v] == -1 && capacity[u][v] > 0) {
                parent[v] = u;
                int new_flow = min(flow, capacity[u][v]);
                if (v == t) return new_flow;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

int edmondsKarp(int s, int t, int n) {
    int max_flow = 0;
    vector<int> parent(n);

    int flow;
    while ((flow = bfs(s, t, parent, n)) > 0) {
        max_flow += flow;
        int v = t;
        while (v != s) {
            int u = parent[v];
            capacity[u][v] -= flow;
            capacity[v][u] += flow;
            v = u;
        }
    }
    return max_flow;
}

int main() {
    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;
    s--; t--;

    memset(capacity, 0, sizeof(capacity));

    for (int i = 0; i < m; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        u--; v--; 
        capacity[u][v] += cap;
    }

    cout << edmondsKarp(s, t, n) << endl;

    return 0;
}
