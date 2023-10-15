from sys import stdin
n = int(input())
for _ in range(n):
    word = stdin.readline().strip()
    score = 0
    for ch in word:
        if ch == ' ':
            continue
        score += ord(ch) - 64
    if score == 100:
        print('PERFECT LIFE')
    else:
        print(score)
