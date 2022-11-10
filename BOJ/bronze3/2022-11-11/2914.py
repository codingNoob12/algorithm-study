a, i = map(int, input().split())
if a == 1:
    m = i
else:
    m = a * (i - 1) + 1
print(m)
