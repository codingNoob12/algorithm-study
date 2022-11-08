while True:
    line = list(map(int, input().split()))
    a = line[0]
    if a == 0:
        break
    res = 1
    for i in range(1, 2 * a + 1, 2):
        res *= line[i]
        res -= line[i + 1]
    print(res)
