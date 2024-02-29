#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int board[N][N];
bool isUsed[3][N][10];
vector<pair<int, int>> zeros;

void bt(int idx) {
    if (idx == zeros.size()) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j];
            cout << "\n";
        }
        exit(0);
    }

    int i = zeros[idx].first;
    int j = zeros[idx].second;

    for (int k = 1; k < 10; k++) {
        if (isUsed[0][i][k] || isUsed[1][j][k] || isUsed[2][3 * (i / 3) + (j / 3)][k])
            continue;
        board[i][j] = k;
        isUsed[0][i][k] = 1;
        isUsed[1][j][k] = 1;
        isUsed[2][3 * (i / 3) + (j / 3)][k] = 1;
        bt(idx + 1);
        isUsed[0][i][k] = 0;
        isUsed[1][j][k] = 0;
        isUsed[2][3 * (i / 3) + (j / 3)][k] = 0;
        board[i][j] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            board[i][j] = line[j] - '0';
            if (!board[i][j]) {
                zeros.push_back({i, j});
            }
            isUsed[0][i][board[i][j]] = 1;                     // 행
            isUsed[1][j][board[i][j]] = 1;                     // 열
            isUsed[2][3 * (i / 3) + (j / 3)][board[i][j]] = 1; // 3x3
        }
    }

    bt(0);
}