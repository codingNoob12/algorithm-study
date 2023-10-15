n = int(input())
cnt = 0
for i in range(n+1):
    cnt += (n - i + 1) * (n + i) // 2 + i * (n - i + 1)
print(cnt)
