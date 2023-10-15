t = int(input())
for _ in range(t):
    yScore, kScore = 0, 0
    for _ in range(9):
        y, k = map(int, input().split())
        yScore += y
        kScore += k
    if yScore > kScore:
        print('Yonsei')
    elif yScore < kScore:
        print('Korea')
    else:
        print('Draw')
