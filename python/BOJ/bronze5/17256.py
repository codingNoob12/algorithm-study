aList = list(map(int, input().split()))
cList = list(map(int, input().split()))
bList = [cList[0] - aList[2], cList[1] // aList[1], cList[2] - aList[0]]
for b in bList:
    print(b, end=' ')
