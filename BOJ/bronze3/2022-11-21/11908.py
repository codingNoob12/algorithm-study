n = int(input())
cList = list(map(int, input().split()))
cList.sort()
print(sum(cList[:-1]))
