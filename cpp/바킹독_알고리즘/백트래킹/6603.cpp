#include <bits/stdc++.h>
using namespace std;

int k;
int num[13];
int arr[6];

void func(int depth, int st) {
	if (depth == 6) {
		for (int e : arr) cout << e << " ";
		cout << "\n";
		return;
	}

	for (int i = st; i < k; i++) {
		arr[depth] = num[i];
		func(depth + 1, i + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> num[i];
		func(0, 0);
		cout << "\n";
	}
}