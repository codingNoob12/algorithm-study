from collections import deque
import sys
input = sys.stdin.readline
q = deque()
for _ in range(int(input())):
    cmd = input().strip().split()
    if cmd[0] == 'push':
        q.appendleft(int(cmd[1]))
    elif cmd[0] == 'pop':
        if q:
            print(q.pop())
        else:
            print(-1)
    elif cmd[0] == 'size':
        print(len(q))
    elif cmd[0] == 'empty':
        print(0 if len(q) else 1)
    elif cmd[0] == 'front':
        if q:
            print(q[-1])
        else:
            print(-1)
    else:
        if q:
            print(q[0])
        else:
            print(-1)
