#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using ll = long long;

int n;
int a[4000], b[4000], c[4000], d[4000];
vector<int> x, y;
vector<pair<ll, ll>> cx, cy; // compressed x, y

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

    cx.push_back({x[0], 1});
    for (int i = 1; i < x.size(); i++) {
        if (cx.back().X == x[i])
            cx.back().Y++;
        else
            cx.push_back({x[i], 1});
    }
    cy.push_back({y[0], 1});
    for (int i = 1; i < y.size(); i++) {
        if (cy.back().X == y[i])
            cy.back().Y++;
        else
            cy.push_back({y[i], 1});
    }

    ll cnt = 0;
    for (auto e : cx) {
        auto l = lower_bound(cy.begin(), cy.end(), make_pair(-e.X, 1ll));
        if (l->X == -e.X)
            cnt += e.Y * l->Y;
    }
    cout << cnt;
}