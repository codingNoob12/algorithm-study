from sys import stdin
t = int(stdin.readline().strip())
for _ in range(t):
    n, k = map(int, stdin.readline().strip().split())
    candies = list(map(int, stdin.readline().strip().split()))
    cnt = 0
    for candy in candies:
        cnt += candy // k
    print(cnt)
