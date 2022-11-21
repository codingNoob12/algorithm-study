lenList = list(map(int, input().split()))
lenList.sort()
a, b, c = lenList
for i in range(a + b - 1, 0, -1):
    if i <= c:
        c = i
        break
print(a + b + c)
