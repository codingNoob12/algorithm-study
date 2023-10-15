n = int(input())
for i in range(5 * n):
    for j in range(5 * n):
        if (j in range(n, 2 * n) and not(i in range(n))) or (j in range(3*n, 4*n) and i in range(4*n)):
            print(' ', end='')
        else:
            print('@', end='')
    print()
