n = int(input())
r, c = 1, 1
for i in range(n):
    if i % 2 == 0:
        r += 1
    else:
        c += 1
print(r * c)
