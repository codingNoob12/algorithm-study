n = int(input())
for i in range(n // 5, -1, -1):
    for j in range((n - 5 * i) // 3, -1, -1):
        if 5 * i + 3 * j == n:
            print(i + j)
            exit(0)
print(-1)
