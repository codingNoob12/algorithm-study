aCards = list(map(int, input().split()))
bCards = list(map(int, input().split()))
aWin, bWin = 0, 0
for i in range(10):
    if aCards[i] > bCards[i]:
        aWin += 1
    elif aCards[i] < bCards[i]:
        bWin += 1
if aWin > bWin:
    print('A')
elif aWin < bWin:
    print('B')
else:
    print('D')
