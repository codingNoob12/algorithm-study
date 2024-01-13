#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int idx[10];
bool is_used[10];
unordered_set<string> is_printed;

void func(int k) {
	if (k == m) {
		string tmp;
		for (int i = 0; i < m; i++) tmp.append(to_string(arr[idx[i]]) + " ");
		if (is_printed.find(tmp) != is_printed.end()) return;
		cout << tmp << "\n";
		is_printed.insert(tmp);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (is_used[i]) continue;
		idx[k] = i;
		is_used[i] = true;
		func(k + 1);
		is_used[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	func(0);
}