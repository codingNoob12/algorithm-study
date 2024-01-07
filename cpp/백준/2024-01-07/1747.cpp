#include <bits/stdc++.h>
using namespace std;

int n;
bool is_prime[2000001];

bool is_palindrome(int x) {
	string s = to_string(x);
	for (int i = 0; i < s.length() / 2; ++i) {
		if (s[i] != s[s.length() - i - 1]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(is_prime + 2, is_prime + 2000001, true);

	for (int i = 2; i <= 2000000; i++) {
		for (int j = 2; j <= 2000000 / i; j++) is_prime[i * j] = false;
	}

	cin >> n;
	while (!is_prime[n] || !is_palindrome(n)) {
		n++;
	}
	cout << n;
}