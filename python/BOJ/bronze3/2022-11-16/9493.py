while True:
    m, a, b = map(int, input().split())
    if m == a == b == 0:
        break
    t = round(abs(m / a - m / b) * 3600)
    print('{}:{:02}:{:02}'.format(t // 3600, t // 60 % 60, t % 60))
