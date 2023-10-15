aCards = list(map(int, input().split()))
bCards = list(map(int, input().split()))
aPoint, bPoint, lastWin = 0, 0, None
for i in range(10):
    if aCards[i] > bCards[i]:
        aPoint += 3
        lastWin = 'A'
    elif aCards[i] < bCards[i]:
        bPoint += 3
        lastWin = 'B'
    else:
        aPoint += 1
        bPoint += 1
print(aPoint, bPoint)
if aPoint > bPoint:
    print('A')
elif aPoint < bPoint:
    print('B')
else:
    if lastWin is None:
        lastWin = 'D'
    print(lastWin)
