a, b, c = map(int, input().split())
time = [0] * 101
for _ in range(3):
    s, e = map(int, input().split())
    for i in range(s, e):
        time[i] += 1
res = 0
for t in time:
    if t not in (1, 2, 3):
        continue
    if t == 1:
        res += a
    elif t == 2:
        res += b * 2
    else:
        res += c * 3
print(res)
