import math

a, b = map(int, input().split())
p = b - a; q = b
gcd = math.gcd(p, q)
p = p // gcd; q = q // gcd
print(p, q)
