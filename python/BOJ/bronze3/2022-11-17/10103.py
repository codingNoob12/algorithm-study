n = int(input())
cntList = [100] * 2
for _ in range(n):
    d1, d2 = map(int, input().split())
    if d1 > d2:
        cntList[1] -= d1
    elif d1 < d2:
        cntList[0] -= d2
for cnt in cntList:
    print(cnt)
