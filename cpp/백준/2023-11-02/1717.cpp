#include <bits/stdc++.h>
using namespace std;

int findParent(int x, vector<int> &parent) {
    if (x == parent[x]) return x;
    parent[x] = findParent(parent[x], parent);
    return parent[x];
}

void unionParent(int a, int b, vector<int> &parent) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a < b) parent[a] = b;
    else parent[b] = a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        int op, a, b;
        cin >> op >> a >> b;
        if (!op) unionParent(a, b, parent);
        else {
            if (findParent(a, parent) == findParent(b, parent)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
/*
 * n이 100만 이하, m이 10만 이하인데, 0 ~ n의 각각의 원소마다 집합을 관리하는 것은 비효율적이다.
 * 자칫하면 메모리 초과가 발생할 수도 있다...
 *
 * 따라서, 유니온 파인드 알고리즘을 이용한다면, 적은 메모리로 원소들의 포함관계를 파악할 수 있다.
 *
 * 배열에 대표값을 저장해서 빠르게 같은 집합인 원소들을 찾을 수 있으므로, 공간복잡도와 시간복잡도가
 * 다른 알고리즘에 비해 낮아 효율적이다.
 */