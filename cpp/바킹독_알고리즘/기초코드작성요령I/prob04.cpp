#include <bits/stdc++.h>

using namespace std;

int func4(int N) {
    int i = 1;
    while (i * 2 <= N) i *= 2;
    return i;
}

int main() {
    int tc[] = {5, 97615282, 1024};
    int res[] = {4, 67108864, 1024};
    bool isCorrect = true;

    for (int i = 0; i < 3; i++) {
        if (func4(tc[i]) != res[i]) {
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