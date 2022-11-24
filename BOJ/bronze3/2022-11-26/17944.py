n, t = map(int, input().split())
cnt, isIncrease = 0, True
for _ in range(t):
    if isIncrease:
        cnt += 1
        if cnt == 2 * n:
            isIncrease = False
    else:
        cnt -= 1
        if cnt == 1:
            isIncrease = True
print(cnt)
