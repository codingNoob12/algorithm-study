# def get2DSum(arr, i, j, x, y):
#     sumVal = 0
#     for row in arr[i-1:x]:
#         sumVal += sum(row[j-1:y])
#     return sumVal
#
# N, M = map(int, input().split())
# arr = [list(map(int, input().split())) for _ in range(N)]
# for _ in range(int(input())):
#     i, j, x, y = map(int, input().split())
#     print(get2DSum(arr, i, j, x, y))

def prefix_sum_2d(N, M, arr, Q):
    pre_sum = [[0 for j in range(M + 1)] for i in range(N + 1)]
    for i in range(1, N + 1):
        for j in range(1, M + 1):
            pre_sum[i][j] = pre_sum[i][j - 1] + pre_sum[i - 1][j] - pre_sum[i - 1][j - 1] + arr[i - 1][j - 1]

    result = []
    for i, j, x, y in Q:
        result.append(pre_sum[x][y] - pre_sum[x][j - 1] - pre_sum[i - 1][y] + pre_sum[i - 1][j - 1])
    return result

N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
Q = [list(map(int, input().split())) for _ in range(int(input()))]
result = prefix_sum_2d(N, M, arr, Q)
for r in result:
    print(r)
