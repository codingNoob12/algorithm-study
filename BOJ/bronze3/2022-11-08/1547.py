m = int(input())
idx = 1
for _ in range(m):
    sw = list(map(int, input().split()))
    if idx in sw:
        sw.remove(idx)
        idx = sw[-1]
print(idx)
