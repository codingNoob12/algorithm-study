#include <bits/stdc++.h>
using namespace std;

/**
 * @param r 행을 제어하는 int형 파라미터
 * @param c 열을 제어하는 int형 파라미터
 * @param n 현재 영역의 한 변의 크기를 제어하는 int형 파라미터
 * @return
 * <li>접근 순서를 long long 형으로 반환.</li>
 * <li>만약 n이 1이라면 0을 리턴</li>
 * @brief <span style="color: white">x와 y를 제어변수로 r행 c열의 <font color='red'>접근 순서를 재귀적으로 구하는 함수</font>이다.</span>
 * @details
 * <p>방문 순서는 <b>Z모양</b>을 재귀적으로 그리는 패턴이다.</p>
 * <p>이 때 방문 순서를 구하려면, 방문할 지점이 위치하는 영역 <font color='red'>이전의 영역들</font>은
 * 전부 방문하게 된다.</p>
 * <p style="color: white">따라서 <b>현재 영역의 한 변의 길이</b>가 n이고 <b>모든 칸을 방문하는 영역들의 갯수</b>를 k라 하면,<br>
 * 위의 이전 영역들에서 방문하는 칸의 갯수는 <b>k * (n / 2) ** 2</b>임을 알 수 있다.</p>
 * <p>이제, 현재 r행 c열이 존재하는 영역만을 바라보면 된다. 여기에서도 동일한 패턴으로 방문 순서가 결졍된다.</p>
 * <p style="color:white">따라서 전체의 1/4 영역만을 바라보게 되므로, 영역의 한 변의 길이는 <b>n / 2</b>가 된다.</p>
 * <p style="color: white">여기에서 방문하는 사각형의 갯수는 재귀함수인 get_order를 이용해
 * <b>get_order(r % (n / 2), c % (n / 2), n / 2)</b>라는 것을 구할 수 있다.</p>
 * <p></p>
 * <p style="color: red">
 * 따라서, 총 방문하는 칸의 갯수는 <b>k * (n / 2) ** 2 + get_order(r % (n / 2), c % (n / 2), n / 2)</b>가 된다.
 * </p>
 * <p>처음 위치는 방문 순서에 포함시키지 않으므로 <b>n = 1일 때, 0을 리턴</b>한다.</p>
 */
int get_order(int r, int c, int n) {
    if (n == 1) return 0;
    n /= 2;
    int squares = n * n, k;
    if (r < n) {
        if (c < n) k = 0;
        else k = 1;
    } else {
        if (c < n) k = 2;
        else k = 3;
    }
    return k * squares + get_order(r % n, c % n, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    cout << get_order(r, c, pow(2, n));
}