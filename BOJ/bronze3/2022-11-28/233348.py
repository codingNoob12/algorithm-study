difficulties = list(map(int, input().split()))
n = int(input())
scores = []
for _ in range(n):
    score = 0
    for _ in range(3):
        tries = list(map(int, input().split()))
        for i in range(3):
            score += tries[i] * difficulties[i]
    scores.append(score)
print(max(scores))
