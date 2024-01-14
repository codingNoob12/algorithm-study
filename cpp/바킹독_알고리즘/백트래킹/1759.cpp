#include <bits/stdc++.h>
using namespace std;

int l, c;
char chars[15];
char arr[15];

bool check_vowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void func(int k, int st, int consonant, int vowel) {
	if (k == l) {
		if (consonant < 2 || vowel < 1) return;
		for (int i = 0; i < l; i++) cout << arr[i];
		cout << "\n";
		return;
	}

	for (int i = st; i < c; i++) {
		arr[k] = chars[i];
		bool is_vowel = check_vowel(chars[i]);
		func(k + 1, i + 1, consonant + !is_vowel, vowel + is_vowel);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> chars[i];
	sort(chars, chars + c);
	func(0, 0, 0, 0);
}