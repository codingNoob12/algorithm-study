#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (!dq.empty() && dq.back().second >= x) dq.pop_back();
        dq.push_back({i, x});
        if (dq.front().first < i - l + 1) dq.pop_front();
        cout << dq.front().second << " ";
    }
}

/*
 * n개의 수와 범위 l이 주어졌을 때, 구간 내 최소값을 찾는 문제
 *
 * n과 l이 500만 이하라서 시간복잡도 O(N^2)은 통과 안된다.
 * i번째 값이 주어지면, 바로 최소값 찾아야 되는데, monotone stack을 변형하면 된다.
 *
 * 어차피, 큰 값은 작은 값에 의해 가려지기 때문에 monotone stack인데,
 * 범위를 벗어나는지 까지 고려해야 되므로 인덱스가 범위 내인지 확인해야한다.
 *
 * 그래서, 원소는 <i, x>의 형태가 되고, 스택을 second의 오름차순으로 관라하자.
 *
 * 내림차순으로 관리하면, top보다 큰 값이 들어오면, 모두 비워버리고 해당 값이 들어가므로,
 * 최소값을 구할 수 없다.
 *
 * 그러면, 아래쪽에서 원소를 꺼내야 하므로, stack이 아닌 deque을 써야한다.
 *
 * 꺼내기 전에, 구간을 벗어난 원소가 있는지 확인해야한다.
 * 구간을 벗어난 원소가 있다면, 1개일 것이다.
 *
 * 매 step마다 1개의 원소가 구간을 벗어나게 되는데,
 * 덱에 여러 원소가 존재하므로, 구간을 벗어난 원소들이 누적되는 경우가 있을 것이라 생각할 수 있다.
 *
 * 하지만, 이는 거짓이다.
 * 왜냐하면, monotone stack의 성질로 인해, x가 최소라면, 덱에는 x만 존재한다.
 * 즉, 덱 안에 원소가 누적되려면, 오름차순으로 원소가 주어져야한다.
 * 따라서, 다음 step에서 범위를 벗어나는 원소의 갯수는 최대 1개이다.
 * 그러므로, front의 first가 범위를 벗어났는지만 확인하고, pop_front하면 된다.
 */