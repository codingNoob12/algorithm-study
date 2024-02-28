#include <bits/stdc++.h>
using namespace std;

int n;
int a[4000], b[4000], c[4000], d[4000];
vector<int> x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x.push_back(a[i] + b[j]);
            y.push_back(c[i] + d[j]);
        }
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long cnt = 0;
    for (auto e : x)
        cnt += upper_bound(y.begin(), y.end(), -e) -
               lower_bound(y.begin(), y.end(), -e);
    cout << cnt;
}