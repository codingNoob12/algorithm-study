import copy

a, b = input().split()
n, m = len(a), len(b)
arr = [copy.deepcopy(['.'] * n) for _ in range(m)]
for j, ch in enumerate(a):
    if ch in b:
        arr[b.find(ch)] = [c for c in a]
        for i in range(m):
            arr[i][j] = b[i]
        break
for line in arr:
    for ch in line:
        print(ch, end='')
    print()
