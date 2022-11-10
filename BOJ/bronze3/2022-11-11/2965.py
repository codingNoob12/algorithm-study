posList = list(map(int, input().split()))
cnt = 0
l, r = posList[1] - posList[0] - 1, posList[2] - posList[1] - 1
while l != 0 or r != 0:
    cnt += 1
    if l > r:
        posList[2] = posList[1] - 1
    else:
        posList[0] = posList[1] + 1
    posList.sort()
    l, r = posList[1] - posList[0] - 1, posList[2] - posList[1] - 1
print(cnt)
