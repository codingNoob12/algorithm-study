#include <bits/stdc++.h>
using namespace std;

int n;
int a[4000], b[4000], c[4000], d[4000];
int two[16'000'002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            two[n * i + j] = c[i] + d[j];
    }

    int sz = n * n;
    sort(two, two + sz);

    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt += upper_bound(two, two + sz, -a[i] - b[j]) -
                   lower_bound(two, two + sz, -a[i] - b[j]);
        }
    }
    cout << cnt;
}