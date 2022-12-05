countDict = {}
for ch in input():
    if ch in countDict.keys():
        countDict[ch] += 1
    else:
        countDict[ch] = 1
for k in sorted(countDict.keys(), reverse=True):
    for _ in range(countDict[k]):
        print(k, end='')
