t = int(input())
tList = [300, 60, 10]
cntList = [0] * 3
if t % tList[-1] != 0:
    print(-1)
else:
    for i in range(3):
        cntList[i] = t // tList[i]
        t %= tList[i]
    for cnt in cntList:
        print(cnt, end=' ')
