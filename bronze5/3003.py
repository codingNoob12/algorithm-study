numList = list(map(int, input().split()))
correctList = [1, 1, 2, 2, 2, 8]
needList = []
for i in range(len(numList)):
    need = correctList[i] - numList[i]
    needList.append(need)
for need in needList:
    print(need, end=' ')
