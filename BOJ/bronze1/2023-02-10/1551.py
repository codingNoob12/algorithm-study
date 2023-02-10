# from copy import deepcopy
# N, K = map(int, input().split())
# arrA = list(map(int, input().split(',')))
# arrB = deepcopy(arrA)
# for _ in range(K):
#     newArrB = []
#     for i in range(1, len(arrB[:])):
#         newArrB.append(arrB[i] - arrB[i-1])
#     arrB = newArrB
# print(*arrB, sep=',')

N, K = map(int, input().split())
arrA = list(map(int, input().split(',')))
for _ in range(K):
    for i in range(N - 1):
        arrA[i] = arrA[i + 1] - arrA[i]
    N -= 1
print(*arrA[:N], sep=',')

