#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    queue<int> cards;
    for (int i = 1; i <= n; i++) cards.push(i);
    while (!cards.empty()) {
        cout << cards.front() << " ";
        cards.pop();
        if (!cards.empty()) {
            cards.push(cards.front());
            cards.pop();
        }
    }
}