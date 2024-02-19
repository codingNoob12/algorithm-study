#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
vector<pair<int, int>> e;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e.push_back({x, 1});
        e.push_back({y, -1});
    }

    sort(e.begin(), e.end());

    int ans = 0, cnt = 0, loc = -1e9;
    for (auto i : e) {
        if (cnt > 0) {
            ans += i.X - loc;
        }
        loc = i.X;
        cnt += i.Y;
    }

    cout << ans;
}