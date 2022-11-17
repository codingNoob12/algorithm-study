n, t = map(int, input().split())
timeList = list(map(int, input().split()))
cnt, totTime = 0, 0
for time in timeList:
    if totTime + time > t:
        break
    totTime += time
    cnt += 1
print(cnt)
