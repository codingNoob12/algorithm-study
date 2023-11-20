#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;

void dfs(int node, int group) {
    visited[node] = group;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, group);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    visited.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        visited[i] = ++ans;
        dfs(i, visited[i]);
    }

    cout << ans;
}