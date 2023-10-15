# N, C = map(int, input().split())
# flare = [False] * (C+1)
# cnt = 0
# for _ in range(N):
#     cycle = int(input())
#     for t in range(cycle, C+1, cycle):
#         if not flare[t]:
#             flare[t] = True
#             cnt += 1
# print(cnt)

import sys
input = sys.stdin.readline
n, c = map(int, input().split())
t = [0] * c
x = {int(input()) for _ in range(n)}
if 1 in x:
    print(c)
    exit(0)
for i in x:
    t[i-1::i] = [1] * (c//i)
print(sum(t))
