from sys import stdin
t = int(stdin.readline().strip())
for _ in range(t):
    n, d = map(int, stdin.readline().strip().split())
    cnt = 0
    for _ in range(n):
        v, f, c = map(int, stdin.readline().strip().split())
        t = d / v
        if f >= c * t:
            cnt += 1
    print(cnt)
