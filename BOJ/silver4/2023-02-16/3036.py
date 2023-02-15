from math import gcd

n = int(input())
standard, *radiusList = map(int, input().split())
for radius in radiusList:
    gcdVal = gcd(standard, radius)
    print(f"{standard // gcdVal}/{radius // gcdVal}")
