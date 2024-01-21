#include <bits/stdc++.h>
using namespace std;

const char BLANK = '.';
const char WALL = '#';

int N, M, P;
string board[1000];
int S[10], area[10];
queue<tuple<int, int, int>> q[10]; // {x, y, step}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int vis[1000][1000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++) cin >> S[i];
	for (int i = 0; i < N; i++) {
		cin >> board[i];
		for (int j = 0; j < M; j++) {
			if (board[i][j] == WALL || board[i][j] == BLANK) continue;
			int p = board[i][j] - '0';
			q[p].push({i, j, 0});
			area[p]++;
			vis[i][j] = p;
		}
	}

	while (true) {
		bool is_extend = false;
		for (int i = 1; i <= P; i++) {
			queue<tuple<int, int, int>> next_q;
			while (!q[i].empty()) {
				int x, y, s;
				tie(x, y, s) = q[i].front();
				q[i].pop();

				if (s >= S[i]) {
					next_q.push({x, y, 0});
					continue;
				}

				for (int dir = 0; dir < 4; dir++) {
					int nx = x + dx[dir], ny = y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (board[nx][ny] == WALL || vis[nx][ny]) continue;

					q[i].push({nx, ny, s + 1});
					vis[nx][ny] = vis[x][y];
					area[i]++;
					is_extend = true;
				}
			}
			q[i] = next_q;
		}

		if (!is_extend) break;
	}

	for (int i = 1; i <= P; i++) cout << area[i] << " ";
}