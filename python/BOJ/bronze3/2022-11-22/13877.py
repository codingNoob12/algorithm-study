from sys import stdin
t = int(input())
for _ in range(t):
    k, n = stdin.readline().strip().split()
    try:
        o = int(n, 8)
    except ValueError:
        o = 0
    finally:
        d, h = int(n), int(n, 16)
    print(k, o, d, h)
