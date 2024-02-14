#include <bits/stdc++.h>
using namespace std;

string a, b, lcs;
int d[1001][1001], idx[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(idx, idx + 1001, -1);

    cin >> a >> b;
    int lenA = a.length(), lenB = b.length();
    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (a[i - 1] == b[j - 1]) {
                d[i][j] = max(d[i][j - 1], d[i - 1][j - 1] + 1);
            } else {
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    cout << d[lenA][lenB] << "\n";
    if (d[lenA][lenB]) {
        int i = lenA, j = lenB;
        while (i > 0 && j > 0) {
            if (d[i][j] > d[i - 1][j] && d[i - 1][j] == d[i][j - 1]) {
                lcs += a[i - 1];
                i--;
                j--;
            } else if (d[i - 1][j] > d[i][j - 1])
                i--;
            else
                j--;
        }

        reverse(lcs.begin(), lcs.end());
        cout << lcs;
    }
}