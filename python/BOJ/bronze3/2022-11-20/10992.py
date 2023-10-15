n = int(input())
for i in range(n):
    for j in range(n-1-i):
        print(' ', end='')
    for j in range(2*i+1):
        if j in (0, 2*i) or i == n-1:
            print('*', end='')
        else:
            print(' ', end='')
    print()
