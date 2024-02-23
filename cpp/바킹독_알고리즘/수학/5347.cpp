#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << lcm(a, b) << "\n";
    }
}