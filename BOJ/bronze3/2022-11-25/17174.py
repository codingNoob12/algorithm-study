n, m = map(int, input().split())
cnt = 0
while n != 0:
    cnt += n
    n //= m
print(cnt)
