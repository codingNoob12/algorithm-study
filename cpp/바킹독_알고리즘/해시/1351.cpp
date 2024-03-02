#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, p, q;
unordered_map<ll, ll> um;

ll solve(ll x) {
	if (x == 0) return 1;
	if (um.find(x / p) == um.end()) um[x / p] = solve(x / p);
	if (um.find(x / q) == um.end()) um[x / q] = solve(x / q);
	return um[x / p] + um[x / q];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> q;
	cout << solve(n);
}