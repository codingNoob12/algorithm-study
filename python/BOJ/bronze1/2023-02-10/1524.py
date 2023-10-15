for _ in range(int(input())):
    for _ in range(2):
        input()
    sejun = sorted(list(map(int, input().split())), reverse=True)
    sebi = sorted(list(map(int, input().split())), reverse=True)
    while sejun and sebi:
        if sejun[-1] >= sebi[-1]:
            sebi.pop()
        else:
            sejun.pop()
    print('S' if sejun else 'B')
