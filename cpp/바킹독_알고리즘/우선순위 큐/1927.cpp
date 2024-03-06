#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0;

void push(int x) {
	heap[++sz] = x;
	for (int i = sz; i / 2 >= 1; i /= 2) {
		if (heap[i / 2] <= heap[i]) break;
		swap(heap[i / 2], heap[i]);
	}
}

int top() {
	return heap[1];
}

void pop() {
	heap[1] = heap[sz--];
	for (int i = 1, c = 2 * i; c <= sz; i = c, c *= 2) {
		if (c + 1 <= sz && heap[c] > heap[c + 1]) c++;
		if (heap[i] <= heap[c]) break;
		swap(heap[i], heap[c]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (!x) {
			if (sz) {
				cout << top() << "\n";
				pop();
			} else cout << 0 << "\n";
		} else push(x);
	}
}