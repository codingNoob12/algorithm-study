a, d, k = map(int, input().split())
n = (k - a) // d + 1
if (k - a) % d != 0 or n <= 0:
    print('X')
else:
    print(n)
