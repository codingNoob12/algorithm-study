#include <bits/stdc++.h>
using namespace std;

int n;
int a[100'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0x7f7f7f7f;
    for (int i = 0; i < n; i++) {
        auto l = lower_bound(a, a + n, -a[i]);
        for (int j = -1; j < 2; j++) {
            if (l + j < a || l + j >= a + n || l + j == a + i)
                continue;
            int c = *(l + j) + a[i];
            if (abs(ans) > abs(c))
                ans = c;
        }
    }
    cout << ans;
}