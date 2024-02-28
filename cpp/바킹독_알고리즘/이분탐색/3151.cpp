#include <bits/stdc++.h>
using namespace std;

int n;
int a[10'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    long long cnt = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            cnt += upper_bound(a + j + 1, a + n, -a[i] - a[j]) - lower_bound(a + j + 1, a + n, -a[i] - a[j]);
        }
    }
    cout << cnt;
}