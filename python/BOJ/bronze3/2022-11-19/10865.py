from sys import stdin
n, m = map(int, input().split())
frdCntList = [0] * n
for _ in range(m):
    frd = tuple(map(int, stdin.readline().strip().split()))
    frdCntList[frd[0] - 1] += 1
    frdCntList[frd[1] - 1] += 1
for cnt in frdCntList:
    print(cnt)
