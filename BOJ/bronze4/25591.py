p, q = map(int, input().split())
a, b = 100 - p, 100 - q
c, d = 100 - (a + b), a * b
q, r = d // 100, d % 100
print(a, b, c, d, q, r)
print(c + q, r)
