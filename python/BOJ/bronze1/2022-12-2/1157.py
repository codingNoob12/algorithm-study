cntDict = {}
for ch in input().upper():
    if ch in cntDict.keys():
        cntDict[ch] += 1
    else:
        cntDict[ch] = 1
maxVal = max(cntDict.values())
maxAlphas = []
for k, v in cntDict.items():
    if v == maxVal:
        maxAlphas.append(k)
print('?' if len(maxAlphas) > 1 else maxAlphas[0])
