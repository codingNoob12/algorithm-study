numList = list(map(int, input().split()))
numList.sort()
diff1 = numList[1] - numList[0]
diff2 = numList[2] - numList[1]
if diff1 < diff2:
    print(numList[1] + diff1)
elif diff1 > diff2:
    print(numList[0] + diff2)
else:
    print(numList[-1] + diff1)
