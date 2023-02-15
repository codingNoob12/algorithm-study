for _ in range(int(input())):
    n = int(input())
    dp = [[0, 0] for _ in range(n + 1)]
    dp[0] = [1, 0]
    if n != 0:
        dp[1] = [0, 1]

    for i in range(2, n + 1):
        for j in range(2):
            dp[i][j] += dp[i - 1][j] + dp[i - 2][j]
    print(*dp[n])
