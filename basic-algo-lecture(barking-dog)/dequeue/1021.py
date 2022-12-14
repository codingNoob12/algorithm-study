from collections import deque
n, m = map(int, input().split())
posList = list(map(int, input().split()))
dq = deque(range(1, n+1))
cnt = 0
for pos in posList:
    if dq.index(pos) <= len(dq) // 2:
        while dq[0] != pos:
            dq.append(dq.popleft())
            cnt += 1
        dq.popleft()
    else:
        while dq[0] != pos:
            dq.appendleft(dq.pop())
            cnt += 1
        dq.popleft()
print(cnt)
