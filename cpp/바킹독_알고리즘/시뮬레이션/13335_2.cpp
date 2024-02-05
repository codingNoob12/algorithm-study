#include <bits/stdc++.h>
using namespace std;

int n, w, L;
int weights[1000], t[1000];
int bridge[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) cin >> weights[i];

	int i = 0, j = 0;
	t[0] = 1;
	while (j < n) {
		int load = 0;
		for (int x = i; x <= j; x++) load += weights[x];

		if (load <= L) j++;
		else i++;

		if (i == 0) t[j] = t[j - 1] + 1;
		else t[j] = max(t[j - 1] + 1, t[i - 1] + w);
	}

	cout << t[n - 1] + w;
}