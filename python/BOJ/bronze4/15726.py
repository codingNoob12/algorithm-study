numList = list(map(int, input().split()))
print(int(max(numList[0] * numList[1] / numList[2],
    numList[0] / numList[1] * numList[2])))
