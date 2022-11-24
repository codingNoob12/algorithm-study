from math import sqrt
a, b = map(int, input().split())
sol1 = int(-a - sqrt(a ** 2 - b))
sol2 = int(-a + sqrt(a ** 2 - b))
if sol1 == sol2:
    print(sol1)
else:
    print(sol1, sol2)
