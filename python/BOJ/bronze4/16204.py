n, m, k = map(int, input().split())
tot = k + n - m if m >= k else m + n - k
print(tot)
