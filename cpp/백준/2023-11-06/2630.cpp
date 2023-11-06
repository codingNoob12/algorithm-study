#include <bits/stdc++.h>
using namespace std;

int paper[129][129];

/**
 * @brief <span style="color: white">파란색 종의의 갯수를 <span style="color:red">재귀적으로</span>
 * 구하는 함수</span>
 * @param n <span style="color: white">종이의 한 변 크기</span>
 * @param x <span style="color: white">행의 시작 인덱스</span>
 * @param y <span style="color: white">열의 시작 인덱스</span>
 * @return
 * <li>해당 영역의 원소가 모두 1이면 1을 리턴</li>
 * <li>그렇지 않으면, 해당 영역을 4분할하여 영역 별 countBlue 함수 값의 합계를 리턴</li>
 * <li>n이 1이면, 해당 위치의 값을 리턴</li>
 */
int countBlue(int n, int x, int y) {
    if (n == 1) return paper[x][y];
    int count = 0;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (!paper[i][j]) break;
            count++;
        }
    }
    if (count == n * n) return 1;
    int nn = n / 2;
    return countBlue(nn, x, y) + countBlue(nn, x, y + nn) +
        countBlue(nn, x + nn, y) + countBlue(nn, x + nn, y + nn);
}

/**
 * @brief <span style="color: white">하얀색 종의의 갯수를 <span style="color:red">재귀적으로</span>구하는 함수</span>
 * @param n <span style="color: white">종이의 한 변 크기</span>
 * @param x <span style="color: white">행의 시작 인덱스</span>
 * @param y <span style="color: white">열의 시작 인덱스</span>
 * @return
 * <li>해당 영역에 있는 모든 원소들이 0이면 1을 리턴</li>
 * <li>그렇지 않으면, 해당 영역을 4분할 하여, 각 영역의 countWhite 연산 결과의 합계를 리턴</li>
 * <li>단, n = 1이면 해당 위치의 원소가 0일 경우 1 리턴, 그렇지 않으면 0을 리턴</li>
 */
int countWhite(int n, int x, int y) {
    if (n == 1) return !paper[x][y];
    int count = 0;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (paper[i][j]) break;
            count++;
        }
    }
    if (count == n * n) return 1;
    int nn = n / 2;
    return countWhite(nn, x, y) + countWhite(nn, x, y + nn) +
        countWhite(nn, x + nn, y) + countWhite(nn, x + nn, y + nn);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> paper[i][j];

    cout << countWhite(n, 1, 1) << "\n";
    cout << countBlue(n, 1, 1);
}