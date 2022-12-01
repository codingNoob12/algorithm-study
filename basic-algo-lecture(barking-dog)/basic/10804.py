nums = list(range(1, 21))
for _ in range(10):
    a, b = map(int, input().split())
    nums = nums[:a-1] + (nums[b-1:a-2:-1] if a > 1 else nums[b-1::-1]) + nums[b:]
print(*nums)
