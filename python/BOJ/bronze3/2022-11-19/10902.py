n = int(input())
f, tf, sf = 0, 0, 0
for i in range(1, n+1):
    t, s = map(int, input().split())
    if sf < s:
        f, tf, sf = i, t, s
p = 0 if sf == 0 else tf + (f - 1) * 20
print(p)
