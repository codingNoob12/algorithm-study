n = int(input())
mins, maxs = [40, 40], [0, 0]
for _ in range(n):
    x, y = map(int, input().split())
    if mins[0] > x:
        mins[0] = x
    if mins[1] > y:
        mins[1] = y
    if maxs[0] < x:
        maxs[0] = x
    if maxs[1] < y:
        maxs[1] = y
print(2 * ((maxs[0] - mins[0]) + (maxs[1] - mins[1])))
