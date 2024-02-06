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

    int l = 0, r = 0, maxCnt = 0;
    long long ans = 0;
    while (r < n) {
        if (cards[l] == cards[r])
            r++;
        else {
            if (maxCnt < r - l) {
                maxCnt = r - l;
                ans = cards[l];
            }
            l = r;
        }
    }
    if (maxCnt < r - l)
        ans = cards[l];
    cout << ans;
}