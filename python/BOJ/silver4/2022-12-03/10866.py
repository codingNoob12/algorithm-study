from collections import deque
import sys
input = sys.stdin.readline
dq = deque()
for _ in range(int(input())):
    cmd = input().strip().split()
    if cmd[0] == 'push_front':
        dq.appendleft(int(cmd[1]))
    elif cmd[0] == 'push_back':
        dq.append(int(cmd[1]))
    elif cmd[0] == 'pop_front':
        if dq:
            print(dq.popleft())
        else:
            print(-1)
    elif cmd[0] == 'pop_back':
        if dq:
            print(dq.pop())
        else:
            print(-1)
    elif cmd[0] == 'size':
        print(len(dq))
    elif cmd[0] == 'empty':
        print(0 if len(dq) else 1)
    elif cmd[0] == 'front':
        if dq:
            print(dq[0])
        else:
            print(-1)
    else:
        if dq:
            print(dq[-1])
        else:
            print(-1)
