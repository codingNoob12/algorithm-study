# def sumOfOneTwoThree(n):
#     global cnt
#     if n in (1, 2, 3):
#         cnt += 1
#
#     for i in range(1, 4):
#         if n > i:
#             sumOfOneTwoThree(n - i)
#
#
# for _ in range(int(input())):
#     cnt = 0
#     sumOfOneTwoThree(int(input()))
#     print(cnt)

for _ in range(int(input())):
    n = int(input())
    dp = [0] * (n + 1)
    dp[0] = 1

    for i in range(1, n + 1):
        if i >= 1:
            dp[i] += dp[i - 1]
        if i >= 2:
            dp[i] += dp[i - 2]
        if i >= 3:
            dp[i] += dp[i - 3]
    print(dp[n])
