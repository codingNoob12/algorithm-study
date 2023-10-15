n = int(input())
xList = list(map(int, input().split()))
newXList = list(set(xList[:]))
newXList.sort()
dic = {x: i for i, x in enumerate(newXList)}
for x in xList:
    print(dic[x], end=" ")
