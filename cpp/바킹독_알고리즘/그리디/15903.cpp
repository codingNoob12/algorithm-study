#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
priority_queue<ll> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(-x);
    }

    for (int i = 0; i < m; i++) {
        ll a, b;
        a = pq.top(), pq.pop(), b = pq.top(), pq.pop();

        pq.push(a + b);
        pq.push(a + b);
    }

    ll ans = 0;
    while (!pq.empty()) {
        ans += -pq.top();
        pq.pop();
    }

    cout << ans;
}