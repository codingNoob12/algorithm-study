#include <bits/stdc++.h>

using namespace std;

// int func3(int n) {
//     int sqrt_n = sqrt(n);
//     if (sqrt_n * sqrt_n == n) {
//         return 1;
//     }
//     return 0;
// }

int func3(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (i * i == n) return 1;
    }
    return 0;
}

int main() {
    int tc[] = {9, 693953651, 756580036};
    int res[] = {1, 0, 1};
    bool isCorrect = true;
    for (int i = 0; i < 3; i++) {
        if (func3(tc[i]) != res[i]) {
            isCorrect = false;
            cout << "오답" << endl;
            break;
        }
    }
    if (isCorrect) {
        cout << "정답" << endl;
    }
    return 0;
}