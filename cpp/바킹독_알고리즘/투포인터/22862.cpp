#include <bits/stdc++.h>
using namespace std;

int n, k, mx;
int s[1'000'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int en = 0, cnt = s[0] % 2 == 0, del = 0;
    for (int st = 0; st < n; st++) {
        if (s[st] % 2) {
            if (del > 0)
                del--;
            continue;
        }

        if (en < st) {
            en = st, cnt = 1;
        }
        while (en < n && del <= k) {
            en++;
            if (en == n)
                continue;
            if (s[en] % 2 == 0)
                cnt++;
            else
                del++;
        }

        mx = max(mx, cnt);
        cnt--;
    }

    cout << mx;
}