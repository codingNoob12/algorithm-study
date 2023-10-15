posList = []
for _ in range(3):
    posList.append(tuple(map(int, input().split())))
posList.sort()
if posList[1][0] == posList[0][0]:
    x = posList[2][0]
    if posList[2][1] == posList[0][1]:
        y = posList[1][1]
    else:
        y = posList[0][1]
else:
    x = posList[0][0]
    if posList[0][1] == posList[1][1]:
        y = posList[2][1]
    else:
        y = posList[1][1]
print(x, y)
