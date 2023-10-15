n = int(input())
for i in range(5 * n):
    for j in range(5 * n):
        if (i in range(n)) or (j in range(n)):
            print('@', end='')
    print()
