#include <bits/stdc++.h>
using namespace std;

int n;
int S[20][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> S[i][j];
	}

	vector<int> team(n, 0);
	fill(next(team.begin(), n / 2), team.end(), 1);

	int ans = 0x7f7f7f7f;
	do {
		int status[2] = {};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (team[i] != team[j]) continue;
				status[team[i]] += S[i][j];
			}
		}
		ans = min(ans, abs(status[0] - status[1]));
	} while (next_permutation(team.begin(), team.end()));

	cout << ans;
}
/*
 * 문제
 * n명이 모여 축구함. (n은 짝수)
 * n/2명씩 2팀으로 사람들을 나눠야함
 *
 * 사람에 1 ~ n번의 번호를 배정 능력치가 2차원으로 주어짐
 * 능력치 Sij는 i번 사람이 j번과 같은 팀에 속했을 때, 팀에 더해지는 능력치
 * 팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합.
 * Sij와 Sji는 다를 수 있으며,
 * i번 사람과 j번 사람이 같은팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.
 *
 * 두 팀의 능력치 차이를 최소화.
 *
 * 입력
 * n, 능력치 정보
 *
 * 출력
 * 능력치 차이의 최솟값
 *
 * //==아이디어==//
 * 백트래킹으로 모든 경우를 따져보기
 * n이 20이하이므로 가짓수는 20C10 = 184,756이 된다.
 *
 * 그리고 각 팀의 능력치의 합을 구하는 방법은 O(n^2)이 된다.
 * 정확히 연산횟수는 10 * 10이 된다.
 *
 * 따라서 총 연산 횟수는 184,756 * 2 * 20 * 20 = 147,804,800번이 된다.
 */