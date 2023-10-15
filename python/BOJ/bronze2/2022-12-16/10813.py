n, m = map(int, input().split())
v = list(range(1, n+1))
for _ in range(m):
    i, j = map(int, input().split())
    v[i-1], v[j-1] = v[j-1], v[i-1]
print(*v)
