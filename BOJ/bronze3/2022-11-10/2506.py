n = int(input())
chkList = list(map(int, input().split()))
cnt, score = 0, 0
for chk in chkList:
    if chk == 1:
        cnt += 1
        score += cnt
    else:
        cnt = 0
print(score)
