scores = list(map(int, input().split()))
maxScores = [100, 100, 200, 200, 300, 300, 400, 400, 500]
for i in range(9):
    if scores[i] > maxScores[i]:
        print('hacker')
        exit(0)
if sum(scores) < 100:
    print('none')
else:
    print('draw')
