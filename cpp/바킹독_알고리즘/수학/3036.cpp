#include <bits/stdc++.h>
using namespace std;

int n;
int r[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> r[i];
    for (int i = 1; i < n; i++) {
        int g = gcd(r[0], r[i]);
        cout << r[0] / g << "/" << r[i] / g << "\n";
    }
}