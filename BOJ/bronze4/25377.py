n = int(input())
tList = []
for _ in range(n):
    a, b = map(int, input().split())
    if a <= b:
        tList.append(b)
if len(tList) == 0:
    print(-1)
else:
    print(min(tList))
