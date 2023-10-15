# sol 1) 함수
# import math
#
# n, k = map(int, input().split())
# print(math.comb(n - 1, k - 1))


# sol 2) DP (bottom-up)
n, k = map(int, input().split())
dp = [[0] * (i + 1) for i in range(n)]
for i in range(n):
    for j in range(i + 1):
        if j in (0, i):
            dp[i][j] = 1
            continue
        for x in range(2):
            dp[i][j] += dp[i - 1][j - x]
print(dp[n - 1][k - 1])
