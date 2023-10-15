a, b, c = map(int, input().split())
if c <= b:
    n = -1
else:
    n = a // (c - b) + 1
print(n)
