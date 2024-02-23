#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int e, s, m;
    cin >> e >> s >> m;

    int i = 1;
    while (1) {
        if ((i - 1) % 15 + 1 == e && (i - 1) % 28 + 1 == s && (i - 1) % 19 + 1 == m) {
            cout << i;
            break;
        }
        i++;
    }
}