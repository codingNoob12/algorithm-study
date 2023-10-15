cntDict = {}
n = int(input())
for num in map(int, input().split()):
    if num in cntDict.keys():
        cntDict[num] += 1
    else:
        cntDict[num] = 1
m = int(input())
res = []
for num in map(int, input().split()):
    cnt = cntDict.get(num)
    if cnt is None:
        cnt = 0
    res.append(cnt)
print(res)
