n = int(input())
for i in range(n):
    for j in range(i, n-1):
        print(' ', end='')
    for j in range(2*i+1):
        if j in (0, 2*i):
            print('*', end='')
        else:
            print(' ', end='')
    print()
