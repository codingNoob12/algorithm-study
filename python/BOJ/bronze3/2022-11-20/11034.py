from sys import stdin
for line in stdin.readlines():
    posList = list(map(int, line.strip().split()))
    cnt = 0
    while True:
        posList.sort()
        a, b, c = posList
        if a == b - 1 and c == b + 1:
            break
        if b - a > c - b:
            posList[2] = b - 1
        else:
            posList[0] = b + 1
        cnt += 1
    print(cnt)
