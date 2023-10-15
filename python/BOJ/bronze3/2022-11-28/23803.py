n = int(input())
for i in range(5 * n):
    for j in range(5 * n):
        if j in range(n) or i in range(4 * n, 5 * n):
            print('@', end='')
    print()
