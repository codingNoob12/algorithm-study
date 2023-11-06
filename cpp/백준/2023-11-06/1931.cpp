#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

/**
 * @brief <span style="color:white">최대한으로 회의실을 많이 사용할 수 있도록 회의실을 배정하는 문제</span>
 * @details
 * <p>회의 시간은 <b>시작 시간</b>과 <b>끝나는 시간</b>이 주어지며, <b>총 N개의 입력</b>이 주어진다.</p>
 * <p style="color: red">N은 최대 10만이며, 회의 시간은 int의 표현 범위를 넘지 않는다.</p>
 * <p style="color: white">배정 가능한 회의의 최대 갯수를 출력한다.</p>
 * <p>즉, 우리는 회의를 가능한 한 많이 배정해야하므로, <b>그리디 알고리즘</b>을 사용해야한다.</p>
 * <br>
 * <p>문제 조건을 살펴보았으니, 이제 풀이를 생각해보자.</p>
 * <p style="color: white">회의실을 배정할 때 중요한 것은 회의실을 이용중일 때,
 * 회의실을 배정할 수 없다는 것이다.</p>
 * <p>즉, A회의의 <b>시작시간부터 종료시간까지</b> 회의실을 사용하지 못한다는 의미이다.</p>
 * <p style="color: red">따라서, 회의가 빠르게 끝나면 곧바로 새로운 회의를 배정할 수 있다는 의미가 된다.</p>
 * <p style="color: white">따라서, 회의 종료시간이 빠른 순으로 정렬해서 순차적으로 배정을 하면 된다.</p>
 * <p><b>배정이 불가능한 경우를 제외</b>해야함을 잊지 말자.</p>
 */
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> meetings(n);
    for (int i = 0; i < n; i++) cin >> meetings[i].first >> meetings[i].second;
    sort(meetings.begin(), meetings.end(), compare);

    auto iter = meetings.begin();
    int ans = 1, end = iter->second;
    iter++;
    for (; iter != meetings.end(); iter++) {
        if (end <= iter->first) {
            ans++;
            end = iter->second;
        }
    }

    cout << ans;
}