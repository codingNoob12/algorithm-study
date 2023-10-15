t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    target = 11 * m + 4
    if target > n * m or m < 4:
        print(-1)
    else:
        print(target)
