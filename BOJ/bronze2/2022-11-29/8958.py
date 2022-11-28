t = int(input())
for i in range(t):
    results = input()
    cnt = 0
    score = 0
    for result in results:
        if result == 'O':
            cnt += 1
            score += cnt
        else:
            cnt = 0
    print(score)
