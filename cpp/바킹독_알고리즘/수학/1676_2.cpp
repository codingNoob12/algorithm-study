#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    // 1부터 n까지의 곱에서 인수 5의 갯수 세기
    while (n) {
        ans += n / 5;
        n /= 5;
    }
    cout << ans;
}