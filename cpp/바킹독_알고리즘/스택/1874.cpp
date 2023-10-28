#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> S;
    vector<char> ans;
    int i = 1;
    while (n--) {
        int num;
        cin >> num;
        while (i <= num) {
            S.push(i++);
            ans.push_back('+');
        }
        if (S.top() != num) {
            cout << "NO";
            return 0;
        }
        S.pop();
        ans.push_back('-');
    }

    for (char ch : ans) {
        cout << ch << "\n";
    }
}