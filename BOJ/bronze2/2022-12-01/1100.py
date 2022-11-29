import sys
cnt = 0
board = list(map(str.strip, sys.stdin.readlines()))
for i in range(len(board)):
    for j in range(len(board[i])):
        if i % 2 == j % 2 and board[i][j] == 'F':
            cnt += 1
print(cnt)
