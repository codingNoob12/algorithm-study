#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
int a[200'000], freq[100'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int st = 0, en = 0; st < n; st++) {
        while (en < n && freq[a[en]] < k) {
            freq[a[en++]]++;
        }

        ans = max(ans, en - st);
        if (en == n)
            break;
        freq[a[st]]--;
    }

    cout << ans;
}