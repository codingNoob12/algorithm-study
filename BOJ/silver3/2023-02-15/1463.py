# sol 1) 메모제이션 : 시간초과
# import sys
#
# sys.setrecursionlimit(10**6)
#
#
# def make1(x, mem):
#     if x == 1:
#         return 0
#
#     if mem[x - 1] != 0:
#         return mem[x - 1]
#
#     candidates = []
#     if x % 3 == 0:
#         candidates.append(make1(x // 3, mem) + 1)
#     if x % 2 == 0:
#         candidates.append(make1(x // 2, mem) + 1)
#     candidates.append(make1(x - 1, mem) + 1)
#     mem[x - 1] = min(candidates)
#     return min(candidates)
#
#
# n = int(input())
# mem = [0] * n
# print(make1(n, mem))


# sol 2) bottom-up
n = int(input())
mem = [0] * (n + 1)
for x in range(2, n + 1):
    candidates = [mem[x - 1]]
    if x % 3 == 0:
        candidates.append(mem[x // 3])
    if x % 2 == 0:
        candidates.append(mem[x // 2])
    mem[x] = min(candidates) + 1
print(mem[n])
