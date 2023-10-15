import math
n = int(input())
nums = list(map(int, input().split()))
factors = []
gcd = math.gcd(*nums)
for i in range(1, int(math.sqrt(gcd)+1)):
    for num in nums:
        if num % i != 0:
            break
    else:
        factors.append(i)
        if i != gcd // i:
            factors.append(gcd // i)
factors.sort()
print(*factors, sep='\n')
