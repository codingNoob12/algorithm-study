n = int(input())
cnt = 0
for i in range(1, n+1):
    for digit in str(i):
        if digit in ('3', '6', '9'):
            cnt += 1
print(cnt)
