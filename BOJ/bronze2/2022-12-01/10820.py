import sys
import string
for line in sys.stdin.readlines():
    cntDict = {'Lower': 0, 'Upper': 0, 'Digit': 0, 'Space': 0}
    for ch in line:
        if ch in string.ascii_lowercase:
            cntDict['Lower'] += 1
        elif ch in string.ascii_uppercase:
            cntDict['Upper'] += 1
        elif ch in string.digits:
            cntDict['Digit'] += 1
        else:
            cntDict['Space'] += 1
    cntDict['Space'] -= 1
    print(*cntDict.values())
