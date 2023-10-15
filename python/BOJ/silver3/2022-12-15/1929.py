import math

m, n = map(int, input().split())
nums = [1] * (n+1)
for i in range(2, int(math.sqrt(n)) + 1):
    if nums[i]:
        for j in range(2, n//i + 1):
            nums[i * j] = 0
for i in range(m, n+1):
    if nums[i] and i != 1:
        print(i)
