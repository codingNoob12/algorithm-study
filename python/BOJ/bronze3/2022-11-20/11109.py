from sys import stdin
t = int(input())
for _ in range(t):
    d, n, s, p = map(int, stdin.readline().strip().split())
    manSpent = d + n * p
    sElapse = n * s
    if manSpent < sElapse:
        print('parallelize')
    elif manSpent > sElapse:
        print('do not parallelize')
    else:
        print('does not matter')
