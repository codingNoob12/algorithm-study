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

    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = b[j++];
    }

    while (i < n)
        tmp[k++] = a[i++];

    while (j < m)
        tmp[k++] = b[j++];

    for (int idx = 0; idx < n + m; idx++)
        cout << tmp[idx] << " ";
}