#include <bits/stdc++.h>
using namespace std;

int n;
int l[27], r[27];

int encode(char c) {
	return c - 'A' + 1;
}

char decode(int x) {
	return x + 'A' - 1;
}

void preorder(int x) {
	cout << decode(x);
	if (l[x]) preorder(l[x]);
	if (r[x]) preorder(r[x]);
}

void inorder(int x) {
	if (l[x]) inorder(l[x]);
	cout << decode(x);
	if (r[x]) inorder(r[x]);
}

void postorder(int x) {
	if (l[x]) postorder(l[x]);
	if (r[x]) postorder(r[x]);
	cout << decode(x);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;
		int ep = encode(parent), el = encode(left), er = encode(right);
		if (left != '.') l[ep] = el;
		if (right != '.') r[ep] = er;
	}

	preorder(1);
	cout << "\n";
	inorder(1);
	cout << "\n";
	postorder(1);
}