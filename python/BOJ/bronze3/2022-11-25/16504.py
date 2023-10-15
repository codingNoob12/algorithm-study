n = int(input())
nums2D = [list(map(int, input().split())) for _ in range(n)]
res = 0
for nums in nums2D:
    res += sum(nums)
print(res)
