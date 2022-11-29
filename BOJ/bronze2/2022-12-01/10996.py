N = int(input())
for i in range(N * 2):
    for j in range(N):
        if i % 2 == j % 2:
            print('*', end='')
        else:
            print(' ', end='')
    print()
