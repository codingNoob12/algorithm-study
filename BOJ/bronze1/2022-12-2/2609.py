import math
x, y = map(int, input().split())
gcd = math.gcd(x, y)
lcd = x * y // gcd
print(gcd, lcd, sep='\n')
