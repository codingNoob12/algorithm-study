#include <bits/stdc++.h>
using namespace std;

int n, m, x;
int d[41];
vector<int> v = {0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[0] = 1, d[1] = 1, d[2] = 2;
    for (int i = 3; i <= 40; i++)
        d[i] = d[i - 1] + d[i - 2];

    cin >> n >> m;
    while (m--) {
        cin >> x;
        v.push_back(x);
    }
    v.push_back(n + 1);

    int ans = 1;
    for (int i = 1; i < v.size(); i++)
        ans *= d[v[i] - v[i - 1] - 1];

    cout << ans;
}