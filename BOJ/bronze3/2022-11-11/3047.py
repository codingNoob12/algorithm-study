numList = list(map(int, input().split()))
orders = input()
numList.sort()
for order in orders:
    if order == 'A':
        print(numList[0], end=' ')
    elif order == 'B':
        print(numList[1], end=' ')
    else:
        print(numList[2], end=' ')
