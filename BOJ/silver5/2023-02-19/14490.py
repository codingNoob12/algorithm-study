# sol 1)
# from math import gcd
#
# n, m = map(int, input().split(":"))
# gcdOfN_M = gcd(n, m)
# print(f"{n // gcdOfN_M}:{m // gcdOfN_M}")


# sol 2)
def gcd(x, y):
    if x < y:
        x, y = y, x
    while y:
        x, y = y, x % y
    return x


n, m = map(int, input().split(":"))
gcd_NM = gcd(n, m)
print(f"{n // gcd_NM}:{m // gcd_NM}")
