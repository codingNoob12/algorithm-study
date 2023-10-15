st = input()
rightScore, leftScore = 0, 0
for i in range(len(st)):
    if i < len(st) // 2:
        rightScore += int(st[i])
    else:
        leftScore += int(st[i])
print('LUCKY' if rightScore == leftScore else 'READY')
