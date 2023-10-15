wScores, kScores = [int(input()) for _ in range(10)], [int(input()) for _ in range(10)]
wScores.sort()
kScores.sort()
print(sum(wScores[-3:]), sum(kScores[-3:]))
