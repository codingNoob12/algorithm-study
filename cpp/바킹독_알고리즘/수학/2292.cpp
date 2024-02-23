#include <bits/stdc++.h>
using namespace std;

int n, x = 1, i = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n > x) {
        x += 6 * i++;
    }
    cout << i;
}