from math import sqrt
n, w, h = map(int, input().split())
m = sqrt(w ** 2 + h ** 2)
for _ in range(n):
    lenth = int(input())
    if lenth <= m:
        print('DA')
    else:
        print('NE')
