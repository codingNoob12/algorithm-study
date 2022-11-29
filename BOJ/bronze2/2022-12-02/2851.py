score = 0
lessScore = 0
for _ in range(10):
    score += int(input())
    if score > 100:
        break
    lessScore = score
if score - 100 <= 100 - lessScore:
    print(score)
else:
    print(lessScore)
