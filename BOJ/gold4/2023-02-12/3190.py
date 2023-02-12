from collections import deque

def collisionCheck(x, y):
    global N, cur
    if x < 0 or x >= N or y < 0 or y >= N or (x, y) in cur:
        return True
    return False

DIRECTIONS = {'up': (-1, 0), 'down': (1, 0), 'left': (0, -1), 'right': (0, 1)}

N = int(input())
K = int(input())
board = [[0] * N for _ in range(N)]
cur = deque()
cur.append((0, 0))
time = 0
direction = 'right'

for _ in range(K):
    x, y = map(int, input().split())
    board[x - 1][y - 1] = 1

L = int(input())
for _ in range(L):
    X, C = input().split()
    X = int(X)
    a, b = DIRECTIONS[direction]
    for _ in range(time, X):
        time += 1
        x, y = cur[-1]
        x += a
        y += b
        if collisionCheck(x, y):
            print(time)
            exit(0)
        cur.append((x, y))
        if board[x][y] != 1:
            cur.popleft()
        else:
            board[x][y] = 0
    if C == 'L':
        if direction == 'up':
            direction = 'left'
        elif direction == 'left':
            direction = 'down'
        elif direction == 'down':
            direction = 'right'
        else:
            direction = 'up'
    else:
        if direction == 'up':
            direction = 'right'
        elif direction == 'right':
            direction = 'down'
        elif direction == 'down':
            direction = 'left'
        else:
            direction = 'up'

a, b = DIRECTIONS[direction]
while True:
    time += 1
    x, y = cur[-1]
    x += a
    y += b
    if collisionCheck(x, y):
        print(time)
        exit(0)
    cur.append((x, y))
    if board[x][y] != 1:
        cur.popleft()
