n = int(input())
xMax, xMin, yMax, yMin = -10_000, 10_000, -10_000, 10_000
for _ in range(n):
    x, y = map(int, input().split())
    if x > xMax:
        xMax = x
    if x < xMin:
        xMin = x
    if y > yMax:
        yMax = y
    if y < yMin:
        yMin = y
print((xMax - xMin) * (yMax - yMin))
