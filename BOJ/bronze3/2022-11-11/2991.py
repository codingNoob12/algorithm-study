a, b, c, d = map(int, input().split())
tList = list(map(int, input().split()))
cntList = [0] * 3
for i in range(3):
    if (tList[i] - 1) % (a + b) < a:
        cntList[i] += 1
    if (tList[i] - 1) % (c + d) < c:
        cntList[i] += 1
for cnt in cntList:
    print(cnt)
