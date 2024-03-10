#include <bits/stdc++.h>
using namespace std;

int n, counter = 1, w, mxLevel;
int lc[10'001], rc[10'001], pr[10'001], c[10'001];

void inorder(int cur) {
	if (lc[cur]) inorder(lc[cur]);
	c[cur] = counter++;
	if (rc[cur]) inorder(rc[cur]);
}

void levelorder(int root) {
	queue<int> q;
	queue<int> wq;
	q.push(root);
	int level = 1;

	while (1) {
		int nxtW = c[q.back()] - c[q.front()] + 1;
		if (w < nxtW) {
			w = nxtW;
			mxLevel = level;
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			if (lc[cur]) wq.push(lc[cur]);
			if (rc[cur]) wq.push(rc[cur]);
		}

		if (wq.empty()) break;

		q = wq;
		wq = queue<int>();
		level++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, l, r;
		cin >> p >> l >> r;
		if (l != -1) {
			lc[p] = l;
			pr[l] = p;
		}
		if (r != -1) {
			rc[p] = r;
			pr[r] = p;
		}
	}

	int root = find(pr + 1, pr + n + 1, 0) - pr;

	inorder(root);

	levelorder(root);
	cout << mxLevel << " " << w;
}