from collections import deque
q = deque([0, 1])
n = int(input())
for i in range(n):
    tmp = q[0] + q[1]
    q.popleft()
    q.append(tmp)
print(q.popleft())
