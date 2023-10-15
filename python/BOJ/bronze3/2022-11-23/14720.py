n = int(input())
storeList = list(map(int, input().split()))
cnt, milk = 0, 0
for store in storeList:
    if milk % 3 == store:
        cnt += 1
        milk += 1
print(cnt)
