maxVal = -1
idx = (-1, -1)
for i in range(9):
    numList = list(map(int, input().split()))
    for j in range(9):
        if maxVal < numList[j]:
            maxVal = numList[j]
            idx = (i+1, j+1)
print(maxVal)
print(*idx)
