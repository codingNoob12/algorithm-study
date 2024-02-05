#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
pair<int, int> coords[100'000];

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.Y != b.Y)
        return a.Y < b.Y;
    return a.X < b.X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coords[i] = {x, y};
    }

    sort(coords, coords + n, compare);

    for (int i = 0; i < n; i++)
        cout << coords[i].X << " " << coords[i].Y << "\n";
}