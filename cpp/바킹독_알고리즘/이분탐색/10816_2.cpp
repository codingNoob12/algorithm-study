#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x) << " ";
    }
}