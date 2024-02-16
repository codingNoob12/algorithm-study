#include <bits/stdc++.h>
using namespace std;

int n, w[100'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];

    sort(w, w + n);
    int mx = w[0] * n;
    for (int i = 1; i < n; i++)
        mx = max(mx, w[i] * (n - i));

    cout << mx;
}