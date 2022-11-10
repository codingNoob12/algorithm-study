moveList = list(map(int, input().split()))
moveList.sort()
area = moveList[0] * moveList[2]
print(area)
