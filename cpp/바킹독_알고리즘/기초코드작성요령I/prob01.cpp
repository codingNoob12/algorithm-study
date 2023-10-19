#include <bits/stdc++.h>

using namespace std;

// O(N)
int func1(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int tc[] = {16, 34567, 27639};
    int res[] = {60, 278812814, 178254968};
    bool isCorrect = true;
    for (int i = 0; i < 3; i++) {
        if (func1(tc[i]) != res[i]) {
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