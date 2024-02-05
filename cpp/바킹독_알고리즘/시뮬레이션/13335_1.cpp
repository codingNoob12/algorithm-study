#include <bits/stdc++.h>
using namespace std;

int n, w, L, t;
int bridge[100];
queue<int> truck;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		truck.push(tmp);
	}

	while (1) {
		int load = 0;
		for (int i = 0; i < w; i++) load += bridge[i];

		if (load <= L) {
			load -= bridge[w - 1];
			for (int i = w - 1; i > 0; i--) bridge[i] = bridge[i - 1];
			bridge[0] = 0;
			if (!truck.empty() && load + truck.front() <= L) {
				bridge[0] = truck.front();
				load += truck.front();
				truck.pop();
			}
		}
		t++;

		if (!load) break;
	}

	cout << t;
}