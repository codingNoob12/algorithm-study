#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
int a[100'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    pair<int, int> ans = {1e9 + 1, 1e9 + 1};
    for (int i = 0; i < n; i++) {
        auto l = lower_bound(a, a + n, -a[i]);
        for (int j = -1; j < 2; j++) {
            if (l + j >= a + n || l + j < a || l + j == a + i)
                continue;
            int c = a[i] + *(l + j);
            if (abs(c) < abs(ans.X + ans.Y)) {
                ans = {a[i], *(l + j)};
            }
        }
    }

    if (ans.X > ans.Y)
        swap(ans.X, ans.Y);

    cout << ans.X << " " << ans.Y;
}