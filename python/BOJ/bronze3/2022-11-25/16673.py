c, k, p = map(int, input().split())
collect = 0
for n in range(1, c+1):
    collect += k * n + p * n ** 2
print(collect)
