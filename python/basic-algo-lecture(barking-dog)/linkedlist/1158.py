# sol 1)
# from collections import deque
# n, k = map(int, input().split())
# dq = deque(range(1, n+1))
# seq = []
# cnt = 0
# while dq:
#     cnt += 1
#     if cnt % k == 0:
#         seq.append(dq.popleft())
#     else:
#         dq.append(dq.popleft())
# print('<', str(seq)[1:-1], '>', sep='')

# sol 2)
n, k = map(int, input().split())
arr, seq = list(range(1, n+1)), []
idx = 0
while arr:
    idx = (idx + k - 1) % len(arr)
    seq.append(arr.pop(idx))
print('<', str(seq)[1:-1], '>', sep='')
