#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[1000], b[1000];
vector<int> va, vb;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            va.push_back(sum);
        }
    }
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = i; j < m; j++) {
            sum += b[j];
            vb.push_back(sum);
        }
    }

    long long ans = 0;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    for (auto e : va) {
        ans += upper_bound(vb.begin(), vb.end(), t - e) - lower_bound(vb.begin(), vb.end(), t - e);
    }
    cout << ans;
}