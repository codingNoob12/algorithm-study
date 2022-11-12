while True:
    lenList = list(map(int, input().split()))
    lenList.sort()
    if lenList[0] == lenList[1] == lenList[2] == 0:
        break
    if lenList[2] >= sum(lenList[:2]):
        print('Invalid')
        continue
    maxCnt = 0
    for l in lenList:
        if lenList.count(l) > maxCnt:
            maxCnt = lenList.count(l)
    if maxCnt == 3:
        print('Equilateral')
    elif maxCnt == 2:
        print('Isosceles')
    else:
        print('Scalene')
