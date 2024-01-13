#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) arr.push_back(i);
	}

	do {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		reverse(arr.begin() + m, arr.end());
	} while (next_permutation(arr.begin(), arr.end()));
}