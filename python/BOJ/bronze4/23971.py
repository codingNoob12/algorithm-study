h, w, n, m = map(int, input().split())
row = h // (n + 1)
if h % (n + 1):
    row += 1
col = w // (m + 1)
if w % (m + 1):
    col += 1
print(row * col)
