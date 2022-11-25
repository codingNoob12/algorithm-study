from sys import stdin
n, x, k = map(int, input().split())
cups = [0] * n
cups[x-1] = 1
for _ in range(k):
    pre, cur = map(int, stdin.readline().strip().split())
    cups[pre-1], cups[cur-1] = cups[cur-1], cups[pre-1]
print(cups.index(1) + 1)
