#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> m[100'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> m[i].second >> m[i].first;

    sort(m, m + n);

    int ans = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (t > m[i].second)
            continue;
        ans++;
        t = m[i].first;
    }

    cout << ans;
}