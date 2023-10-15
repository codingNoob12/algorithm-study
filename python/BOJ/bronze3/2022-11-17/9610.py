n = int(input())
cntDict = {'Q1': 0, 'Q2': 0, 'Q3': 0, 'Q4': 0, 'AXIS': 0}
for _ in range(n):
    x, y = map(int, input().split())
    if x == 0 or y == 0:
        idx = 'AXIS'
    elif x > 0:
        idx = 'Q1' if y > 0 else 'Q4'
    else:
        idx = 'Q2' if y > 0 else 'Q3'
    cntDict[idx] += 1
for key in cntDict.keys():
    print(f'{key}: {cntDict[key]}')
