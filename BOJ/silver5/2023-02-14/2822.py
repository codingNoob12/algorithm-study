from copy import deepcopy
scores = [int(input()) for _ in range(8)]
sortedScores = sorted(deepcopy(scores), reverse=True)[:5]
indexList = sorted(scores.index(score) + 1 for score in sortedScores)
print(sum(sortedScores))
print(*indexList)
