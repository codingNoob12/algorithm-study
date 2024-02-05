#include <bits/stdc++.h>
using namespace std;

const int MAX_LMT = 1'000'000'000;
const int MIN_LMT = -1'000'000'000;

int n;
int arr[11];
int cnt[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> cnt[i];

	int mx = MIN_LMT, mn = MAX_LMT, idx = 0;
	vector<int> opr(n - 1);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < cnt[i]; j++) opr[idx++] = i;
	}

	do {
		int result = arr[0];
		for (int i = 0; i < n - 1; i++) {
			switch (opr[i]) {
				case 0: result += arr[i + 1];
					break;
				case 1: result -= arr[i + 1];
					break;
				case 2: result *= arr[i + 1];
					break;
				default: result /= arr[i + 1];
			}
		}
		mx = max(mx, result);
		mn = min(mn, result);
	} while (next_permutation(opr.begin(), opr.end()));
	cout << mx << "\n" << mn;
}
/*
 * 문제
 * n개의 수로 이루어진 수열 A가 주어진다.
 * 수와 수 사이에 끼워넣을 수 있는 n-1개의 연산자가 주어진다.
 * 연산자는 +, -, *, /으로만 이루어져 있다.
 *
 * 수와 수 사이에 연산자를 하나씩 넣어서 수식을 만들 수 있다.
 * 이때, 주어진 수의 순서를 바꾸면 안된다.
 *
 * 식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다.
 * 또, 나눗셈은 정수 나숫셈으로 몫만 취한다.
 * 음수를 양수로 나눌 때는 C++14의 기준을 따른다.
 * 즉, 양수로 바뀐뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다.
 *
 * 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성
 *
 * 입력
 * 수의 개수 n
 * 수열 A
 * 합이 n-1인 4개의 정수; 순서대로 +, -, *, /의 개수가 된다.
 *
 * 출력
 * 만들 수 있는 식의 결과의 최댓값, 최솟값 출력
 * 식의 연산 결과와 중간 단계는 모두 -10억 ~ 10억이다. => 정수 표현 O
 *
 * //==아이디어==//
 * 백트래킹으로 덧셈, 뺄셈, 곱셈, 나눗셈이 들어갈 자리를 결정.
 * 연산하고 최댓값과 최소값을 갱신.
 *
 * 0: 덧셈, 1: 뺄셈, 2: 곱셈, 3: 나눗셈으로 하고 각각을 주어진 연산자 갯수만큼 채워 넣는다.
 * 이후, next_permutation을 이용해서 모든 가능한 경우를 따진다.
 * 연산자의 갯수는 최대 10개 이므로, 가짓수가 10!보단 적다.
 *
 * 각각의 식에서 결과를 계산하는데는 10번의 연산이 필요하다.
 * 그리고, 최댓값과 최솟값을 갱신하기 위해 각각 조건식과 갱신 2회씩을 한다면, 총 4회의 연산이 이루어진다.
 *
 * 총 연산 횟수는 10! * 14 = 50,803,200으로 1초 이내에 수행이 완료된다.
 */