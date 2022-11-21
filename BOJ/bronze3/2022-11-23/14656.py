n = int(input())
posList = list(map(int, input().split()))
cnt = 0
for i in range(n):
    if i + 1 != posList[i]:
        cnt += 1
print(cnt)
