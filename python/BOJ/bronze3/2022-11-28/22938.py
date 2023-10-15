from math import sqrt
x1, y1, r1 = map(int, input().split())
x2, y2, r2 = map(int, input().split())
distBetweenCenters = sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
if r1 + r2 > distBetweenCenters or distBetweenCenters < abs(r1 - r2):
    print('YES')
else:
    print('NO')
