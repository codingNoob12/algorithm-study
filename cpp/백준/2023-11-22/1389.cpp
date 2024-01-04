#include <bits/stdc++.h>

using namespace std;

int sumBacon[101], n, m, bacon[101];
bool graph[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    for (int i = 1; i <= n; i++) {
        fill(bacon, bacon + 101, 0);
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 1; j <= n; j++) {
                if (i == j || bacon[j] || !graph[node][j]) continue;
                bacon[j] = bacon[node] + 1;
                q.push(j);
            }
        }
        for (int j = 1; j <= n; j++) sumBacon[i] += bacon[j];
    }

    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (sumBacon[ans] > sumBacon[i]) ans = i;
    }
    cout << ans;
}