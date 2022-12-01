cntDict = {}
keys = ['1', '2', '3', '4', '5', '6 or 9', '7', '8', '0']
for ch in input():
    if ch in '69':
        ch = '6 or 9'
    if ch in cntDict.keys():
        cntDict[ch] += 1
    else:
        cntDict[ch] = 1
if '6 or 9' in cntDict.keys():
    cntDict['6 or 9'] = cntDict['6 or 9'] // 2 if cntDict['6 or 9'] % 2 == 0 else cntDict['6 or 9'] // 2 + 1
print(max(cntDict.values()))
