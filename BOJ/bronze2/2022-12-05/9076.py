for _ in range(int(input())):
    scores = list(map(int, input().split()))
    scores.sort()
    del scores[0], scores[-1]
    tot = sum(scores)
    if scores[-1] - scores[0] >= 4:
        print('KIN')
    else:
        print(tot)
