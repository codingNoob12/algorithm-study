#include <bits/stdc++.h>
using namespace std;

int n, ans;
int s[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = n - 2; i >= 0; i--) {
        while (s[i] >= s[i + 1]) {
            s[i]--;
            ans++;
        }
    }

    cout << ans;
}