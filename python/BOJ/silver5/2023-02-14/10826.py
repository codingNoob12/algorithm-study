from collections import deque
q = deque()
n = int(input())
for i in range(n + 1):
    if i in (0, 1):
        q.append(i)
        continue
    q.append(q.popleft() + q[0])
print(q[-1])
