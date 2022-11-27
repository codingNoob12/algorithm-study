n = int(input())
for i in range(n + 2):
    for j in range(n + 2):
        if (i in (0, n+1)) or (j in (0, n+1)):
            print('@', end='')
        else:
            print(' ', end='')
    print()
