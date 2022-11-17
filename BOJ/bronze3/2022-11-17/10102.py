v = int(input())
cntDict = {'A': 0, 'B': 0}
for ch in input():
    cntDict[ch] += 1
if cntDict['A'] > cntDict['B']:
    print('A')
elif cntDict['A'] < cntDict['B']:
    print('B')
else:
    print('Tie')
