#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, ans, room;
vector<pair<int, int>> e;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int s, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        e.push_back({s, 1});
        e.push_back({t, -1});
    }

    sort(e.begin(), e.end());
    for (auto i : e) {
        room += i.Y;
        ans = max(ans, room);
    }

    cout << ans;
}