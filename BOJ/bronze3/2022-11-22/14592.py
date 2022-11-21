n = int(input())
scoreList = [tuple(map(int, input().split())) for _ in range(n)]
rankList = sorted(scoreList, key=lambda x: (-x[0], x[1], x[2]))
print(scoreList.index(rankList[0]) + 1)
