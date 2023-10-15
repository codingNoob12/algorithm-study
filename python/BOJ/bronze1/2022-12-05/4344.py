for _ in range(int(input())):
    scores = list(map(int, input().split()[1:]))
    avg = sum(scores) / len(scores)
    cnt = 0
    for s in scores:
        if s > avg:
            cnt += 1
    print(f'{cnt / len(scores) * 100:.3f}%')
