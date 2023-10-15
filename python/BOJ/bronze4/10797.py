day = int(input())
carNumList = list(map(int, input().split()))
cnt = 0
for carNum in carNumList:
    if carNum % 10 == day % 10:
        cnt += 1
print(cnt)
