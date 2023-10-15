n = int(input())
for i in range(5 * n):
    for j in range(5 * n):
        if i in range(n) or i in range(4 * n, 5 * n) or j in range(n):
            print('@', end='')
    print()
