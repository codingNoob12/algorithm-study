import sys
sumVal = 0
lines = sys.stdin.readlines()
for line in lines:
    sumVal += int(line)
print(sumVal)
