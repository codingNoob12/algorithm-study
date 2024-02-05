#include <bits/stdc++.h>
using namespace std;

#define AGE first
#define NAME second

int n;
pair<int, string> users[100'000];

bool compare(const pair<int, string> &a, const pair<int, string> &b) {
    return a.AGE < b.AGE;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;
        users[i] = {age, name};
    }

    stable_sort(users, users + n, compare);

    for (int i = 0; i < n; i++)
        cout << users[i].AGE << " " << users[i].NAME << "\n";
}