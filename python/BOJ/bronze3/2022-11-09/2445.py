n = int(input())
for i in range(n):
    for j in range(2 * n):
        if j <= i or j >= 2 * n - 1 - i:
            print("*", end="")
        else:
            print(" ", end="")
    print()
for i in range(n - 1):
    for j in range(2 * n):
        if n - 1 - i <= j <= n + i:
            print(" ", end="")
        else:
            print("*", end="")
    print()
