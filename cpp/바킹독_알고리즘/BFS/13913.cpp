#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100001;
const int NOT_VISITED = -1;

int n, k;
int vis[MAX_SIZE];
int history[MAX_SIZE];
queue<int> q;

void bfs() {
	q.push(n);
	vis[n] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == k) break;

		if (x - 1 >= 0 && vis[x - 1] == NOT_VISITED) {
			q.push(x - 1);
			vis[x - 1] = vis[x] + 1;
			history[x - 1] = x;
		}
		if (x + 1 < MAX_SIZE && vis[x + 1] == NOT_VISITED) {
			q.push(x + 1);
			vis[x + 1] = vis[x] + 1;
			history[x + 1] = x;
		}
		if (2 * x < MAX_SIZE && vis[2 * x] == NOT_VISITED) {
			q.push(2 * x);
			vis[2 * x] = vis[x] + 1;
			history[2 * x] = x;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(vis, vis + MAX_SIZE, NOT_VISITED);
	fill(history, history + MAX_SIZE, NOT_VISITED);

	cin >> n >> k;
	bfs();
	cout << vis[k] << "\n";
	list<int> ans;
	int p = k;
	while (history[p] != -1) {
		ans.push_front(p);
		p = history[p];
	}
	ans.push_front(p);
	for (auto e : ans) cout << e << " ";
}
/*
 * 수빈이 이동 (1초 뒤)
 * 1. x-1
 * 2. x+1
 * 3. 2*x
 *
 * 남동생 찾는 최단 시간 구하기 + 이동
 * bfs 사용
 * 시간과 이전 좌표를 모두 기록
 */