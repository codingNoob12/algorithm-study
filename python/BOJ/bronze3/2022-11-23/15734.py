l, r, a = map(int, input().split())
while a > 0:
    a -= 1
    if l > r:
        r += 1
    else:
        l += 1
print(min(l, r) * 2)
