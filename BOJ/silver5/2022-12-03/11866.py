n, k = map(int, input().split())
lst = list(range(1, n+1))
res, idx = [], 0
while lst:
    idx = (idx + k - 1) % len(lst)
    res.append(lst.pop(idx))
print('<' + str(res)[1:-1] + '>')
