#include <bits/stdc++.h>
using namespace std;

int n;
string serials[50];

bool compare(string &a, string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    int aDigitSum = 0, bDigitSum = 0;
    for (int i = 0; i < a.size(); i++) {
        if (isdigit(a[i]))
            aDigitSum += a[i] - '0';
        if (isdigit(b[i]))
            bDigitSum += b[i] - '0';
    }
    if (aDigitSum != bDigitSum)
        return aDigitSum < bDigitSum;
    return a.compare(b) < 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> serials[i];

    sort(serials, serials + n, compare);

    for (int i = 0; i < n; i++)
        cout << serials[i] << "\n";
}