k, n = map(int, input().split())
if n == 1:
    print(-1)
else:
    x = (k * n) // (n - 1) if (k * n) % (n - 1) == 0 else (k * n) // (n - 1) + 1
    print(x)
