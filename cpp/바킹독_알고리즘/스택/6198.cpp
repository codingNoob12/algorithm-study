#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans = 0;
    cin >> n;
    stack<int> S;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        while (!S.empty() && S.top() <= h) S.pop();
        ans += S.size();
        S.push(h);
    }

    cout << ans;
}

/**
 * 이 문제는 건물을 우측에 있는 건물 중 옥상을 확인할 수 있는 건물 갯수의 총 합을 구하는 문제이다.
 * 또, loop의 방향을 역방향으로 바꾸지 않는 한, loop의 진행 방향과 관리인이 보는 방향이 동일하다.
 *
 * 이는, 2중 loop가 아니면, 현재 건물에서 옥상을 확인할 수 있는 건물의 갯수를 곧바로 파악하기
 * 힘들다는 의미가 된다.
 *
 * 따라서, 관점을 달리해보자.
 * 만약, 현재 건물의 옥상을 바라볼 수 있는 건물들의 갯수를 센다면?
 * 현재 건물의 이전 건물들 중, 현재 건물보다 높이가 높은 건물들의 갯수를 세면 된다.
 *
 * 이는, 스택에 현재 건물보다 높이가 높은 건물들의 높이를 저장하면,
 * 스택의 길이가 우리가 원하는 값이 된다.
*/