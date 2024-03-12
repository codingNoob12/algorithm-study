#include <bits/stdc++.h>
using namespace std;

int n, m;
string name[1001], s1, s2;
unordered_map<string, int> id;
vector<int> adj[1001], anc, ch[1001];
int indeg[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> name[i];
	sort(name + 1, name + n + 1);
	for (int i = 1; i <= n; i++) id[name[i]] = i;

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s1 >> s2;
		adj[id[s2]].push_back(id[s1]);
		indeg[id[s1]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (!indeg[i]) anc.push_back(i);
	}

	cout << anc.size() << "\n";
	for (int i : anc) cout << name[i] << " ";
	cout << "\n";

	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
		for (int c : adj[i]) {
			if (indeg[c] - indeg[i] == 1) ch[i].push_back(c);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << name[i] << " " << ch[i].size() << " ";
		for (int c : ch[i]) cout << name[c] << " ";
		cout << "\n";
	}
}