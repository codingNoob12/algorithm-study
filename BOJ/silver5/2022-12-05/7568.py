infoList = [tuple(map(int, input().split())) for _ in range(int(input()))]
ranks = []
for i in range(len(infoList)):
    rank = 0
    for j in range(len(infoList)):
        x, y = infoList[i]
        p, q = infoList[j]
        if p > x and q > y:
            rank += 1
    ranks.append(rank + 1)
print(*ranks)
