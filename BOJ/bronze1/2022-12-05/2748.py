from collections import deque
q = deque()
for i in range(int(input()) + 1):
    if i in (0, 1):
        q.append(i)
    else:
        q.append(sum(q))
        q.popleft()
print(q[-1])
