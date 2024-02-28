#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> state(n + 1, 1);
    state[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        for (int j = i * i; j <= n; j += i)
            state[j] = 0;
    }
    for (int i = 2; i <= n; i++) {
        if (state[i])
            primes.push_back(i);
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    vector<int> primes = sieve(n);

    int sum = primes[0], en = 0, ans = 0, sz = primes.size();
    for (int st = 0; st < sz; st++) {
        while (en < sz && sum < n) {
            en++;
            if (en != sz)
                sum += primes[en];
        }

        if (sum == n)
            ans++;
        sum -= primes[st];
    }
    cout << ans;
}