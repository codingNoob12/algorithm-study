while True:
    a, b = map(int, input().split())
    if a == b == 0:
        break
    c = 2 * a - b
    print(c)
