#include <bits/stdc++.h>
using namespace std;

int n, t[16], p[16], ans;
bool rsv[16];
vector<int> pays;

bool isAvailable(int x) {
    if (x + t[x] > n)
        return 0;

    for (int i = x; i < x + t[x]; i++) {
        if (rsv[i])
            return 0;
    }
    return 1;
}

void bt(int x) {
    for (int i = x; i < x + t[x]; i++)
        rsv[i] = 1;
    pays.push_back(p[x]);

    int sum = 0;
    for (int pay : pays)
        sum += pay;
    ans = max(ans, sum);

    for (int i = x; i < n; i++) {
        if (isAvailable(i))
            bt(i);
    }

    for (int i = x; i < x + t[x]; i++)
        rsv[i] = 0;
    pays.pop_back();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> p[i];

    for (int i = 0; i < n; i++) {
        if (isAvailable(i))
            bt(i);
    }

    cout << ans;
}