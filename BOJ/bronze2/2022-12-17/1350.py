n = int(input())
files = list(map(int, input().split()))
cluster = int(input())
totCnt = 0
for file in files:
    cnt = file // cluster
    if file - cluster * cnt:
        cnt += 1
    totCnt += cnt
print(totCnt * cluster)
