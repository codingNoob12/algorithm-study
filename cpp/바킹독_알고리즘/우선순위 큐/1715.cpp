#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    int ans = 0;
    while (pq.size() > 1) {
        int a, b;
        a = pq.top(), pq.pop(), b = pq.top(), pq.pop();
        ans += a + b;
        pq.push(a + b);
    }

    cout << ans;
}