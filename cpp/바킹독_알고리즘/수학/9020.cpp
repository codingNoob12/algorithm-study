#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000;

int tc;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> isPrime(MX + 1, 1);
    isPrime[1] = 0;
    for (int i = 2; i * i <= MX; i++) {
        if (!isPrime[i])
            continue;
        for (int j = i * i; j <= MX; j += i)
            isPrime[j] = 0;
    }

    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i = n / 2; i >= 2; i--) {
            if (isPrime[i] && isPrime[n - i]) {
                cout << i << " " << n - i << "\n";
                break;
            }
        }
    }
}