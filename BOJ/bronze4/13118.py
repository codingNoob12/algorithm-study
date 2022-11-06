posList = list(map(int, input().split()))
x, y, r = map(int, input().split())
if posList.__contains__(x):
    print(posList.index(x) + 1)
else:
    print(0)
