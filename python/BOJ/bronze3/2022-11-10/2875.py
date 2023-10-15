n, m, k = map(int, input().split())
n -= k
maxTeam = min(n // 2, m)
for i in range(k):
    n += 1
    m -= 1
    tmp = min(n // 2, m)
    if maxTeam < tmp:
        maxTeam = tmp
print(maxTeam)
