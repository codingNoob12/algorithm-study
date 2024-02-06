#include <bits/stdc++.h>
using namespace std;

int tc, n, m;
int a[20'000], b[20'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--) {
        int ans = 0;

        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(a, a + n, greater<int>());
        sort(b, b + m, greater<int>());

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && a[i] <= b[j])
                j++;
            ans += m - j;
        }
        cout << ans << "\n";
    }
}
/*
기본적으로 O(NM)의 시간복잡도로 답을 구할 수 있다.
그런데, n과 m은 20,000이하이므로 연산 횟수는 대략 8억으로 시간 초과가 난다.
이를 해결하기 위해, 정렬을 해보자.

만약, 내림차순으로 정렬하면, a[i]와 b[j]를 비교해서 답을 구할 수 있다.
*/