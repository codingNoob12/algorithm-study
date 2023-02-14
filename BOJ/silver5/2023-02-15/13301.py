def radius(n):
    if n in (1, 2):
        RADIUS[n - 1], RADIUS[n - 2] = 1, 1
        return 1
    if RADIUS[n - 2] == 0:
        RADIUS[n - 2] = radius(n - 1)
    if RADIUS[n - 3] == 0:
        RADIUS[n - 3] = radius(n - 2)
    return RADIUS[n - 2] + RADIUS[n - 3]


n = int(input())
RADIUS = [0] * n
RADIUS[n - 1] = radius(n)
a, b = 0, 0
if n == 1:
    a, b = RADIUS[-1], RADIUS[-1]
else:
    a, b = RADIUS[-1], RADIUS[-1] + RADIUS[-2]
print(2 * (a + b))
