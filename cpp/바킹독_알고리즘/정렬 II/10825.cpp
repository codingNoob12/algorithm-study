#include <bits/stdc++.h>
using namespace std;

#define NAME get<0>
#define KOR get<1>
#define ENG get<2>
#define MATH get<3>

string name;
int n, kor, eng, math;
tuple<string, int, int, int> students[100'000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> kor >> eng >> math;
        students[i] = {name, kor, eng, math};
    }

    sort(students, students + n, [](const tuple<string, int, int, int> &a, const tuple<string, int, int, int> &b) {
        if (KOR(a) != KOR(b))
            return KOR(a) > KOR(b);
        if (ENG(a) != ENG(b))
            return ENG(a) < ENG(b);
        if (MATH(a) != MATH(b))
            return MATH(a) > MATH(b);
        return NAME(a) < NAME(b);
    });

    for (int i = 0; i < n; i++)
        cout << NAME(students[i]) << "\n";
}