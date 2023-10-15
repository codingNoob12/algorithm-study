n = int(input())
nums = [i * n + i for i in range(1, n)]
print(sum(nums))
