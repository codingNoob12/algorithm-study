#include <bits/stdc++.h>
using namespace std;

int n, m, mx;
int board[501][501];
vector<vector<vector<int>>> tetromino;

//x번째 테트로미노 시계방향 90도 회전
void rotate(int x) {
	vector<vector<int>> tmp;
	for (int j = 0; j < tetromino[x][0].size(); j++) {
		vector<int> row;
		for (int i = tetromino[x].size() - 1; i >= 0; i--) row.push_back(tetromino[x][i][j]);
		tmp.push_back(row);
	}
	tetromino[x] = tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	tetromino.push_back({{1, 1, 1, 1}});
	tetromino.push_back({{1, 1}, {1, 1}});
	tetromino.push_back({{1, 0}, {1, 0}, {1, 1}});
	tetromino.push_back({{0, 1}, {0, 1}, {1, 1}});
	tetromino.push_back({{1, 0}, {1, 1}, {0, 1}});
	tetromino.push_back({{0, 1}, {1, 1}, {1, 0}});
	tetromino.push_back({{1, 1, 1}, {0, 1, 0}});

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> board[i][j];
	}

	for (int dir = 0; dir < 4; dir++) {
		for (int idx = 0; idx < tetromino.size(); idx++) {
			for (int i = 0; i < n - tetromino[idx].size() + 1; i++) {
				for (int j = 0; j < m - tetromino[idx][0].size() + 1; j++) {
					int sum = 0;
					for (int x = 0; x < tetromino[idx].size(); x++) {
						for (int y = 0; y < tetromino[idx][x].size(); y++) {
							if (tetromino[idx][x][y]) sum += board[i + x][j + y];
						}
					}
					mx = max(mx, sum);
				}
			}

			rotate(idx);
		}
	}

	cout << mx;
}
/*
 * 문제
 * 폴리오미노: 1x1 정사각형을 여러 개 이어 붙인 도형
 * - 정사각형은 겹치면 안된다.
 * - 도형은 모두 연결되어 있어야 한다.
 * - 정사각형의 변끼리 연결되어 있어야 한다.
 *
 * 정사각형 4개를 이어 붙이 폴리오미노 = 테트로미노 (5가지)
 *
 * N by M 종이 위에 테트로미노 하나를 놓으려고 한다.
 * 테트로미노 하나를 적절히 놓아서 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램 작성
 * 테트로미노는 반드시 정확히 하나의 칸을 포함하도록 놓아야하며 회전이나 대칭을 시켜도 된다.
 *
 * 입력
 * 세로크기 N과 가로크기 M
 * 종이에 쓰여 있는 수
 *
 * 출력
 * 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값
 *
 * //==아이디어==//
 * 회전과 대칭을 구현해서 직접 가능한 모든 칸에 테트로미노 놓아보는 방법밖에 없는듯?
 * 근데, 그림 그려보니까 대칭시킨거는 그냥 많지도 않은데 구현하지 말고 일일히 적어 넣어도 될듯?
 * 솔직히 좌우 대칭만 구현하면 나머지는 회전시키다보면 전체 경우의 수가 고려되니까
 * 도형이 좌우 대칭인 건 대칭시켜도 동일한 거 나온다는 거 알 수 있음. 3개가 좌우 대칭이니까
 * 5 + 2로 7가지가 나오고 이걸 회전 돌려가며 파악하면 된다는 의미가 되는데?
 *
 * 그냥 메모리 좀 더 쓰지뭐
 *
 * 각각에 대해서 2중 루프 돌면서 합을 구해보자.
 *
 * 근데 테크로미노가 크기가 다 달라서 vector에다 저장해놓고 꺼내쓰는게 이득일듯?
 *
 * 총 7 * 4 * 2500 * 6 = 420,000이라 1초 이내에 돌아갈듯
 */