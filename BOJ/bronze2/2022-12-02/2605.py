n = int(input())
nums = list(map(int, input().split()))
row = []
for i in range(1, n+1):
    row.insert(nums[i-1], i)
print(*row[::-1])
