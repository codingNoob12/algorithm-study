#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int e;
			cin >> e;
			if (e == 1) home.push_back({i, j});
			else if (e == 2) chicken.push_back({i, j});
		}
	}

	vector<bool> mask(chicken.size(), 1);
	fill(mask.begin(), next(mask.begin(), m), 0);

	int mn = INT_MAX;
	do {
		int dist = 0;
		for (auto e : home) {
			int tmp = INT_MAX;
			for (int i = 0; i < mask.size(); i++) {
				if (mask[i]) continue;
				tmp = min(tmp, abs(e.X - chicken[i].X) + abs(e.Y - chicken[i].Y));
			}
			dist += tmp;
		}
		mn = min(mn, dist);
	} while (next_permutation(mask.begin(), mask.end()));

	cout << mn;
}
/*
 * 문제
 * N by N 크기의 도시.
 * 치킨거리 = 집과 가장 가까운 치킨집사이의 거리
 * 도시의 치킨거리 = 모든 집의 치킨거리의 합
 * 거리 = abs(r1 - r2) + abs(c1 - c2)
 *
 * 입력
 * 도시 크기(N), 남겨둘 치킨집(M)
 * 도시 정보: 0=빈칸, 1=집, 2=치킨집
 *
 * 출력
 * 치킨집 M개 골랐을 때, 도시의 치킨거리의 최솟값
 *
 * //==아이디어1==//
 * 도시 전체를 저장할 필요 없이, 집과 치킨집정보를 각각 저장해두고 치킨집중 M개를 선택해 루프돌려가며
 * 각 집의 치킨거리를 구하고 도시의 치킨거리의 최소값을 구하자.
 *
 * 백트래킹으로 M개 치킨집 고르고 치킨거리 구하면 될듯?
 * 이건 next_permutation으로 구해야될 거 같은데? mask로 해서 0인걸 살리고 1인걸 지운다고 가정하면,
 * 0은 M개 나머지는 1로 mask만들면 되고
 *
 * 최악
 * 2400C13 * 2 * 50 * 13
 *
 * 하지만, 문제에서 통과했다. 다행히 1초 이내로 풀리는 방법이었다 ㅠㅠ
 * 다른 풀이 생각도 안났는데 다행이다 ㅠㅠㅠ
 */