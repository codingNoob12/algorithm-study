from collections import deque
t = int(input())
resDeq = deque()
while t > 0:
    resDeq.appendleft(t % 9)
    t //= 9
for i in resDeq:
    print(i, end='')
