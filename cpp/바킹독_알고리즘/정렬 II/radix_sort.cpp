#include <bits/stdc++.h>
using namespace std;

int n = 15;
int arr[1000001] = {12, 421, 46, 674, 103, 502, 7, 100, 21, 545, 722, 227, 62, 91, 240};
int d = 3;  // 최대 자릿수
int p10[3]; // 10의 k승

int digitNum(int x, int a) {
    return (x / p10[a]) % 10;
}

vector<int> l[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    p10[0] = 1;
    for (int i = 1; i < d; i++)
        p10[i] = p10[i - 1] * 10;
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < 10; j++)
            l[j].clear();
        for (int j = 0; j < n; j++)
            l[digitNum(arr[j], i)].push_back(arr[j]);
        int aIdx = 0;
        for (int j = 0; j < 10; j++) {
            for (auto x : l[j])
                arr[aIdx++] = x;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}