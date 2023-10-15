n = int(input())
priceList = []
for _ in range(n):
    diceList = list(map(int, input().split()))
    maxCnt = 0
    diceList.sort()
    for dice in diceList:
        cnt = diceList.count(dice)
        if maxCnt < cnt:
            maxCnt = cnt
    if maxCnt == 3:
        price = diceList[0] * 1000 + 10000
    elif maxCnt == 2:
        price = diceList[1] * 100 + 1000
    else:
        price = diceList[2] * 100
    priceList.append(price)
print(max(priceList))
