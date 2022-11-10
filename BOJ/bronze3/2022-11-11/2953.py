n, maxScore = -1, 0
for i in range(1, 6):
    score = sum(list(map(int, input().split())))
    if maxScore < score:
        maxScore = score
        n = i
print(n, maxScore)
