scienceScores = []
societyScores = []
for _ in range(4):
    scienceScores.append(int(input()))
for _ in range(2):
    societyScores.append(int(input()))
scienceScores.remove(min(scienceScores))
sumVal = sum(scienceScores) + max(societyScores)
print(sumVal)
