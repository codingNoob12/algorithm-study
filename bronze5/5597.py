checkList = [0] * 31
for i in range(28):
    std = int(input())
    checkList[std] = 1
for i in range(1, 31):
    if not checkList[i]:
        print(i)
