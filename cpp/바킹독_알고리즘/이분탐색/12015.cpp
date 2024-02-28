#include <bits/stdc++.h>
using namespace std;

int n, sz;
int a[1'000'000], lis[1'000'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(lis, lis + sz, a[i]) - lis;
        lis[idx] = a[i];
        sz = max(sz, idx + 1);
    }
    cout << sz;
}