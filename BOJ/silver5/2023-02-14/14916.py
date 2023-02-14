n = int(input())
for i in range(n // 5, -1, -1):
    j = (n - i * 5) // 2
    if i * 5 + j * 2 == n:
        print(i + j)
        break
else:
    print(-1)
