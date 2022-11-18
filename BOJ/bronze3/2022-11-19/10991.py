n = int(input())
for i in range(n):
    for j in range(i, n-1):
        print(' ', end='')
    for j in range(2*i+1):
        if j % 2 == 0:
            print('*', end='')
        else:
            print(' ', end='')
    print()
