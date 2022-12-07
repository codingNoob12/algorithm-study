n, m, l = map(int, input().split())
cnt, idx = [0] * n, 0
cnt[0] = 1
while max(cnt) != m:
    idx = (idx + l) % n
    cnt[idx] += 1
print(sum(cnt)-1)
