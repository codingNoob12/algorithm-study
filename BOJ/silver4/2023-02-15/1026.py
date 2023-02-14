n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
sortedA, sortedB = sorted(a, reverse=True), sorted(b)
minS = 0
while sortedB:
    itemA, itemB = sortedA.pop(), sortedB.pop()
    minS += itemA * itemB
print(minS)
