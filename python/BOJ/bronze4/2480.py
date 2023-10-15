diceList = list(map(int, input().split()))
maxCnt = 0
idx = 0
for i in range(3):
    dice = diceList[i]
    cnt = diceList.count(dice)
    if maxCnt < cnt:
        maxCnt = cnt
        idx = i
money = 0
if maxCnt == 3:
    money += 10000 + diceList[idx] * 1000
elif maxCnt == 2:
    money += 1000 + diceList[idx] * 100
else:
    money += max(diceList) * 100
print(money)
