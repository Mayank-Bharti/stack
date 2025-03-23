#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &passengers, bool &hasPassenger) {
    visited[node] = true;
    if (passengers[node] == 1) hasPassenger = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, passengers, hasPassenger);
        }
    }
}

int minBuses(int n, vector<int> &passengers, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    // Build the adjacency list
    for (auto &edge : edges) {
        int u = edge[0] - 1; // Convert to 0-based index
        int v = edge[1] - 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int busCount = 0;
    
    // Perform DFS on each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool hasPassenger = false;
            dfs(i, graph, visited, passengers, hasPassenger);
            if (hasPassenger) busCount++;
        }
    }

    return busCount;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<int> passengers(n);
        for (int i = 0; i < n; i++) {
            cin >> passengers[i];
        }

        vector<vector<int>> edges(n - 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edges[i] = {u, v};
        }

        cout << minBuses(n, passengers, edges) << endl;
    }

    return 0;
}
