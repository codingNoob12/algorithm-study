n, k = map(int, input().split())
xList = []
for i in range(1, n+1):
    if i % 10 == k % 10 or i % 10 == 2 * k % 10:
        continue
    xList.append(i)
print(len(xList))
print(*xList)
