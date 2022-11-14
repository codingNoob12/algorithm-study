from math import sqrt
cnt = 1
while True:
    a, b, c = map(int, input().split())
    if a == b == c == 0:
        break
    print(f'Triangle #{cnt}')
    if c == -1:
        c = sqrt(a ** 2 + b ** 2)
        print('c = {:.3f}'.format(c))
    elif a >= c or b >= c:
        print('Impossible.')
    elif a == -1:
        a = sqrt(c ** 2 - b ** 2)
        print('a = {:.3f}'.format(a))
    elif b == -1:
        b = sqrt(c ** 2 - a ** 2)
        print('b = {:.3f}'.format(b))
    cnt += 1
    print()
