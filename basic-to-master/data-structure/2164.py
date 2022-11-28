# sol 1)
# from collections import deque as dq
# n = int(input())
# q = dq([i for i in range(1, n+1)])
# doPop = True
# while len(q) > 1:
#     if doPop:
#         q.popleft()
#     else:
#         tmp = q.popleft()
#         q.append(tmp)
#     doPop = not doPop
# print(q.pop())

# sol 2)
from collections import deque

N = int(input())
dq = deque(range(1, N+1))

while len(dq) > 1:
    dq.popleft()
    dq.append(dq.popleft())

print(dq.popleft())
