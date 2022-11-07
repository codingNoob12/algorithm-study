n, m = map(int, input().split())
tmp = m if m % 2 == 0 else m - 1
tot = (n // 2) * tmp
if n % 2 == 1:
    tot += m // 2
if m % 2 == 1:
    tot += n // 2
print(tot)
