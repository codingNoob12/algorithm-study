n, m = map(int, input().split())
nums = list(map(int, input().split()))
multiply = 1
for num in nums:
    multiply *= num
print(multiply % m)
