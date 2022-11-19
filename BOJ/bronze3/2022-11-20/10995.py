n = int(input())
for i in range(n):
    for j in range(2*n):
        if i % 2 == j % 2:
            print('*', end='')
        else:
            print(' ', end='')
    print()
