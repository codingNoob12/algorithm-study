#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int a[30'000], freq[3'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d >> k >> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    freq[c] = 1;
    for (int st = 0, en = 0; st < n; st++) {
        do {
            if (a[en] != c)
                freq[a[en]]++;
            en = (en + 1) % n;
        } while (en != (st + k) % n);

        int cnt = 0;
        for (int i = 1; i <= d; i++) {
            cnt += freq[i] > 0;
        }
        ans = max(ans, cnt);

        if (a[st] != c)
            freq[a[st]]--;
    }

    cout << ans;
}