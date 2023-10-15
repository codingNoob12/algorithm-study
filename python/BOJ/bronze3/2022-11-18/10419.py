tc = int(input())
for _ in range(tc):
    d = int(input())
    t = 1
    while d >= t + t ** 2:
        t += 1
    print(t - 1)
