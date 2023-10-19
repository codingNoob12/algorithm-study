#include <bits/stdc++.h>

using namespace std;

// O(N^2)
int func2(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] + arr[j] == 100) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int tc[3][2][4] = {
            {{1, 52, 48}, 3},
            {{50, 42}, 2},
            {{4, 13, 63, 87}, 4}
    };
    int res[] = {1, 0, 1};
    bool isCorrect = true;
    for (int i = 0; i < 3; i++) {
        if (func2(tc[i][0], tc[i][1][0]) != res[i]) {
            cout << "오답" << endl;
            isCorrect = false;
            break;
        }
    }
    if (isCorrect) {
        cout << "정답" << endl;
    }
    return 0;
}