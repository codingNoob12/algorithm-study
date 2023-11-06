#include <bits/stdc++.h>

using namespace std;

int g[101][101];
int visited[101];

void initGraph();

int setGraph();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 10;
    for (int i = 1; i <= tc; i++) {
        initGraph();
        int start = setGraph();
        int node = start;
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            for (int idx = 0; idx < 101; idx++) {
                if (!g[node][idx]) continue;
                if (visited[idx]) continue;
                q.push(idx);
                visited[idx] = visited[node] + 1;
            }
        }
        int lastMax = 100;
        for (int idx = 99; idx > 0; idx--) {
            if (visited[lastMax] < visited[idx]) lastMax = idx;
        }
        cout << "#" << i << " " << lastMax << "\n";
    }
}

void initGraph() {
    fill(visited, visited + 101, 0);
    for (auto &idx : g) {
        fill(idx, idx + 101, 0);
    }
}

int setGraph() {
    int len, start;
    cin >> len >> start;
    for (int i = 0; i < len / 2; i++) {
        int from, to;
        cin >> from >> to;
        g[from][to] = 1;
    }
    return start;
}