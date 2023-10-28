#include <bits/stdc++.h>
using namespace std;
#define N first
#define H second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<pair<int, int>> S;
    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        while (!S.empty() && S.top().H < h) S.pop();
        if (S.empty()) cout << 0 << " ";
        else cout << S.top().N << " ";
        S.push({i, h});
    }
}

/**
 * 현재 탑보다 높이가 높거나 같은 가장 가까운 탑을 구하려면, 스택에 높이가 작은 탑을 제거하면,
 * 높이가 크거나 같은 것들만 존재한다.
 * 그 중, 스택의 loop의 진행 방향에 의해, 스택의 top이 현재 탑에 가장 가까우므로
 * 이 탑의 위치를 출력하면 된다.
 * 하지만, 스택에 높이만 저장한다면, 위치정보를 알 방법이 없으므로,
 * 스택에 위치 정보도 같이 저장해야 한다.
*/