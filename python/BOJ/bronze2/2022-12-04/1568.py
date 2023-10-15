n = int(input())
k, cnt = 1, 0
while n:
    if n < k:
        k = 1
    n -= k
    k += 1
    cnt += 1
print(cnt)
