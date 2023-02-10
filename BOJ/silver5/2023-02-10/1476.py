# range of E : 1 ~ 15
# range of S : 1 ~ 28
# range of M : 1 ~ 19
E, S, M = map(int, input().split())
i, j, k, cnt = 1, 1, 1, 1
while i != E or j != S or k != M:
    i = i % 15 + 1
    j = j % 28 + 1
    k = k % 19 + 1
    cnt += 1
print(cnt)
