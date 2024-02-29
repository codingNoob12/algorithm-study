#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
pair<double, double> coords[10000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(1);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> coords[i].X >> coords[i].Y;
    }

    double area = 0;
    for (int i = 1; i < n - 1; i++) {
        pair<double, double> u = {coords[i].X - coords[0].X, coords[i].Y - coords[0].Y};
        pair<double, double> v = {coords[i + 1].X - coords[0].X, coords[i + 1].Y - coords[0].Y};
        area += (u.X * v.Y - u.Y * v.X) / 2.0;
    }
    cout << abs(area);
}