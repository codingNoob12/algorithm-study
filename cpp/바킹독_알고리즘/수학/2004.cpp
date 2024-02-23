#include <bits/stdc++.h>
using namespace std;

int n, m;

int freq(int x, int a) {
    int cnt = 0;
    while (x) {
        cnt += x / a;
        x /= a;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cout << min(freq(n, 5) - freq(m, 5) - freq(n - m, 5), freq(n, 2) - freq(m, 2) - freq(n - m, 2));
}