#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    queue<int> cards;
    for (int i = 1; i <= n; i++) cards.push(i);
    bool isDiscard = true;
    while (cards.size() != 1) {
        if (!isDiscard)
            cards.push(cards.front());
        cards.pop();
        isDiscard = !isDiscard;
    }
    cout << cards.front();
}