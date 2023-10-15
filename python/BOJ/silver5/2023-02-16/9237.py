n = int(input())
tList = list(map(int, input().split()))
tList.sort()
trees, day = [], 1

while tList:
    day += 1
    trees.append(tList.pop())
for i in range(len(trees)):
    trees[i] -= len(trees) - i - 1
    if trees[i] < 0:
        trees[i] = 0
print(day + max(trees))
