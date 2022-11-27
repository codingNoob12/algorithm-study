n = int(input())
for i in range(5 * n):
    for j in range(5 * n):
        if i in range(n, 4*n) and j in range(n, 4*n):
            print(' ', end='')
        else:
            print('@', end='')
    print()
