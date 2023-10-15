n, m = map(int, input().split())
board = [input() for _ in range(n)]
cntList = []
for start in ('W', 'B'):
    for i in range(n-7):
        for j in range(m-7):
            cnt = 0
            for r in range(i, i+8):
                for c in range(j, j+8):
                    if r % 2 == c % 2:
                        if board[r][c] == start:
                            cnt += 1
                    else:
                        if board[r][c] != start:
                            cnt += 1
            cntList.append(cnt)
print(min(cntList))
