n = int(input())
for i in range(5*n):
    for j in range(5*n):
        if j in range(n) or j in range(4*n, 5*n) or i in range(2*n, 3*n) or i in range(4*n, 5*n):
            print('@', end='')
        else:
            print(' ', end='')
    print()
