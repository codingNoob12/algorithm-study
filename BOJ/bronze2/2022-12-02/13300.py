n, k = map(int, input().split())
cntDict = {}
for _ in range(n):
    s, y = map(int, input().split())
    if cntDict.get((y, s)):
        cntDict[(y, s)] += 1
    else:
        cntDict[(y, s)] = 1
room = 0
for value in cntDict.values():
    room += value // k if value % k == 0 else value // k + 1
print(room)
