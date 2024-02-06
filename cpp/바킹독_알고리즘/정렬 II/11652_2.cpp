#include <bits/stdc++.h>
using namespace std;

int n;
long long cards[100'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> cards[i];

    sort(cards, cards + n);

    int cnt = 0, maxCnt = 0;
    long long ans = -(1ll << 62) - 1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || cards[i - 1] == cards[i])
            cnt++;
        else {
            if (maxCnt < cnt) {
                maxCnt = cnt;
                ans = cards[i - 1];
            }
            cnt = 1;
        }
    }
    if (maxCnt < cnt)
        ans = cards[n - 1];
    cout << ans;
}