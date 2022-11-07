n, w, h, l = map(int, input().split())
r = w // l; c = h // l
maxCnt = r * c
if n > maxCnt:
    n = maxCnt
print(n)
