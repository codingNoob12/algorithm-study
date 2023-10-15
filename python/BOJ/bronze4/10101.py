angleList = []
for _ in range(3):
    angle = int(input())
    angleList.append(angle)
if sum(angleList) == 180:
    maxCnt = 0
    for angle in angleList:
        cnt = angleList.count(angle)
        if maxCnt < cnt:
            maxCnt = cnt
    if maxCnt == 3:
        print("Equilateral")
    elif maxCnt == 2:
        print("Isosceles")
    else:
        print("Scalene")
else:
    print("Error")
