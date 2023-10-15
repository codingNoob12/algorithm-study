import sys
from collections import deque
input = sys.stdin.readline
for _ in range(int(input())):
    left, right = deque(), deque()
    for ch in input().strip():
        if ch == '<':
            if left:
                right.appendleft(left.pop())
        elif ch == '>':
            if right:
                left.append(right.popleft())
        elif ch == '-':
            if left:
                left.pop()
        else:
            left.append(ch)
    print(''.join(left) + ''.join(right))
