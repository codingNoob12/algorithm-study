#include <bits/stdc++.h>
using namespace std;

int n, a[100'000];
bool appear[100'001];
long long cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int st = 0, en = 0; st < n; st++) {
        while (en < n && !appear[a[en]]) {
            appear[a[en++]] = 1;
        }
        cnt += en - st;
        appear[a[st]] = 0;
    }
    cout << cnt;
}