n = int(input())
cnt = 0
for i in range(2, n, 2):
    for j in range(1, n - i):
        k = n - i - j
        if j - k >= 2:
            cnt += 1
print(cnt)
