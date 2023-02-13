n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]
_, k = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(m)]
for x in range(n):
    row = []
    for y in range(k):
        sumVal = 0
        for z in range(m):
            sumVal += A[x][z] * B[z][y]
        row.append(sumVal)
    print(*row)
