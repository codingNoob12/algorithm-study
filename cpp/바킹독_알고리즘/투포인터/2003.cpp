#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, cnt;
int a[10000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll sum = a[0];
    for (int st = 0, en = 0; st < n; st++) {
        while (en < n && sum < m) {
            en++;
            if (en != n)
                sum += a[en];
        }

        if (sum == m)
            cnt++;
        sum -= a[st];
    }

    cout << cnt;
}