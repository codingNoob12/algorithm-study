n = int(input())
scoreList = []
for _ in range(n):
    a, d, g = map(int, input().split())
    score = a * (d + g)
    if a == (d + g):
        score *= 2
    scoreList.append(score)
print(max(scoreList))
