from math import gcd

for _ in range(int(input())):
    n, *nums = map(int, input().split())
    gcdList = []
    for i, x in enumerate(nums):
        for y in nums[i + 1 :]:
            gcdList.append(gcd(x, y))
    print(sum(gcdList))
