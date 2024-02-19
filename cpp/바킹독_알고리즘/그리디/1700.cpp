#include <bits/stdc++.h>
using namespace std;

int n, k, ans, cnt;
int p[100], e[100];

bool isUsing(int x) {
    for (int i = 0; i < cnt; i++) {
        if (p[i] == x)
            return 1;
    }
    return 0;
}

int replace(int x) {
    int idx = 0;
    vector<int> index(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = x; j < k; j++) {
            if (p[i] == e[j]) {
                index[i] = j;
                break;
            }
        }
        if (index[i] == -1)
            return i;
        if (index[i] > index[idx]) {
            idx = i;
        }
    }
    return idx;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> e[i];

    for (int i = 0; i < k; i++) {
        if (isUsing(e[i]))
            continue;
        if (cnt < n)
            p[cnt++] = e[i];
        else {
            p[replace(i)] = e[i];
            ans++;
        }
    }

    cout << ans;
}