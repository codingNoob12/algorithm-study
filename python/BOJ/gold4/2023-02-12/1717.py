# import sys
# sys.setrecursionlimit(10**6)
# input = sys.stdin.readline
# n, m = map(int, input().rstrip().split())
#
# # 각 원소의 대표 원소를 저장하는 리스트
# parent = [i for i in range(n+1)]
#
# def find(x):
#     # x의 대표 원소를 찾는 함수
#     if parent[x] == x:
#         return x
#     parent[x] = find(parent[x])
#     return parent[x]
#
# for _ in range(m):
#     op, a, b = map(int, input().rstrip().split())
#     if op == 0:
#         # a와 b의 대표 원소를 찾은 후, 작은 것을 큰 것의 대표 원소로 연결
#         a = find(a)
#         b = find(b)
#         if a < b:
#             parent[b] = a
#         else:
#             parent[a] = b
#     else:
#         # a와 b의 대표 원소가 같은지 확인
#         print('YES' if find(a) == find(b) else 'NO')

import sys

def find(x):
    if x == parent[x]:
        return x
    parent[x] = find(parent[x])
    return parent[x]

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
n, m = map(int, input().rstrip().split())
parent = [i for i in range(n + 1)]
for _ in range(m):
    op, a, b = map(int, input().rstrip().split())
    if op == 0:
        a = find(a)
        b = find(b)
        if a < b:
            parent[a] = b
        else:
            parent[b] = a
    else:
        print('YES' if find(a) == find(b) else 'NO')
