n = int(input())
candidates = []
maxLength = 0
for i in range(n, n // 2 - 1, -1):
    candidate = [n, i]
    while candidate[-2] - candidate[-1] >= 0:
        candidate.append(candidate[-2] - candidate[-1])
    candidates.append(candidate)
    e = i - 1
    maxLength = max(len(candidate), maxLength)
print(maxLength)
for candidate in candidates:
    if len(candidate) == maxLength:
        print(*candidate)
        break
