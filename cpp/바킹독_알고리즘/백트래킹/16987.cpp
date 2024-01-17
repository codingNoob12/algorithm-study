#include <bits/stdc++.h>
using namespace std;

const int S = 0;
const int W = 1;

int n, ans, cnt;
int eggs[10][2];

void solve(int k) {
	//마지막 계란까지 내리친 결과를 포함시켜야 하므로 k가 n일때가 base-case임
	if (k == n) {
		ans = max(ans, cnt);
		return;
	}
	//현재 손에 든 계란이 깨졌거나 손에 든 계란을 제외한 계란들 중 깨지지 않은 계란이 없는 경우
	if (eggs[k][S] <= 0 || cnt == n - 1) {
		solve(k + 1);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (k == i || eggs[i][S] <= 0) continue;
		eggs[k][S] -= eggs[i][W];
		eggs[i][S] -= eggs[k][W];
		if (eggs[k][S] <= 0) cnt++;
		if (eggs[i][S] <= 0) cnt++;
		solve(k + 1);
		if (eggs[k][S] <= 0) cnt--;
		if (eggs[i][S] <= 0) cnt--;
		eggs[k][S] += eggs[i][W];
		eggs[i][S] += eggs[k][W];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> eggs[i][S] >> eggs[i][W];
	solve(0);
	cout << ans;
}
/*
 * 입력: 계란 갯수(n), n개 계란의 내구도(Si)와 무게(Wi)
 *
 * 처리
 * 1. 가장 왼쪽 계란을 든다.
 * 2. 손에 든 계란으로 깨지지 않은 다른 계란 중 하나를 친다. (선택)
 *   단, 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다.
 * 3. 다음 계란으로 넘어가 1번부터 반복
 *
 * 출력: 깰 수 있는 계란의 최대 개수
 */
// 추가) cnt가 n개일 때 바로 n을 출력하고 프로그램 종료해도 됨. (최적화)