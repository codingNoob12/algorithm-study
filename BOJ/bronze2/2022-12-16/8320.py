import math

n = int(input())
r, c, cnt = 1, 1, 1
while True:
    c += 1
    if r * c > n:
        r += 1
        c = r
        if r > math.sqrt(n):
            break
    cnt += 1
print(cnt)
