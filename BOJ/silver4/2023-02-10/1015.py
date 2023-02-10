# N = int(input())
# A = list(map(int, input().split()))
# P = [0] * N
# cnt = 0
# for i in range(1, 1001):
#     while i in A:
#         idx = A.index(i)
#         A[idx] = 0
#         P[idx] = cnt
#         cnt += 1
# print(*P)

N = int(input())
a = list(map(int, input().split()))
b = sorted(a)
ans = []

for i in range(N):
    ans.append(b.index(a[i]))
    b[ans[-1]] = 0
print(*ans)
