while True:
    a, b, c, d = map(int, input().split())
    if a == b == c == d == 0:
        break
    cnt = 0
    while a != b or b != c or c != d or d != a:
        a, b, c, d = abs(a - b), abs(b - c), abs(c - d), abs(d - a)
        cnt += 1
    print(cnt)
