#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    cnt[s[0] - '0']++;
    for (int i = 1; i < s.length(); i++) {
        if (s[i - 1] != s[i])
            cnt[s[i] - '0']++;
    }
    cout << min(cnt[0], cnt[1]);
}