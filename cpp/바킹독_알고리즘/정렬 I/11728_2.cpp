#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1'000'000], b[1'000'000], tmp[2'000'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int a_idx = 0, b_idx = 0;
    for (int i = 0; i < n + m; i++) {
        if (a_idx == n)
            tmp[i] = b[b_idx++];
        else if (b_idx == m)
            tmp[i] = a[a_idx++];
        else if (a[a_idx] < b[b_idx])
            tmp[i] = a[a_idx++];
        else
            tmp[i] = b[b_idx++];
    }

    for (int i = 0; i < n + m; i++)
        cout << tmp[i] << " ";
}