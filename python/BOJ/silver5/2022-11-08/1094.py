n = int(input())
cnt = 0
for i in range(6, -1, -1):
    divisor = pow(2, i)
    if n // divisor:
        n -= divisor
        cnt += 1
print(cnt)
