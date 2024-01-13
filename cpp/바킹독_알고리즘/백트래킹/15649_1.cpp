#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector<int> arr;
	for (int i = 1; i <= n; i++) arr.push_back(i);

	do {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		reverse(arr.begin() + m, arr.end());
	} while (next_permutation(arr.begin(), arr.end()));
}
