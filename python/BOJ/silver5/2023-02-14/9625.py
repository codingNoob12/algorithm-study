aCount, bCount = 1, 0
n = int(input())
for _ in range(n):
    aCount, bCount = bCount, aCount + bCount
print(aCount, bCount)
