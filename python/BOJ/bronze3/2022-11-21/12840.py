from sys import stdin
h, m, s = map(int, input().split())
totSecond = h * 3600 + m * 60 + s
q = int(input())
for _ in range(q):
    query = stdin.readline().strip()
    if len(query) == 1:
        print(totSecond // 3600 % 24, totSecond // 60 % 60, totSecond % 60)
    else:
        t, c = map(int, query.split())
        if t == 1:
            totSecond += c
        elif t == 2:
            totSecond -= c
        if totSecond < 0:
            totSecond += 24 * 3600
