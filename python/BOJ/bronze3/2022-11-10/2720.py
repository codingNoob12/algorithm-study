t = int(input())
unitList = [25, 10, 5, 1]
for _ in range(t):
    c = int(input())
    for unit in unitList:
        print(c // unit, end=' ')
        c %= unit
    print()
