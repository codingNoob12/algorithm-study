n = int(input())
cntDict = {}
for _ in range(n):
    player = input()
    if cntDict.get(player[0]):
        cntDict[player[0]] += 1
    else:
        cntDict[player[0]] = 1
res = []
for key, value in cntDict.items():
    if value >= 5:
        res.append(key)
res.sort()
if res:
    print(''.join(res))
else:
    print('PREDAJA')
