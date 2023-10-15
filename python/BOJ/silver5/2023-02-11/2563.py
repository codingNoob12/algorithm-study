canvas = [[0 for _ in range(101)] for _ in range(101)]
for _ in range(int(input())):
    x, y = map(int, input().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            canvas[i][j] = 1
cells = 0
for row in canvas:
    cells += sum(row)
print(cells)
