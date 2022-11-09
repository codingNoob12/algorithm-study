cost = tuple(map(int, input().split()))
minCost = cost[0] / cost[1] * 1000
n = int(input())
for _ in range(n):
    cost = tuple(map(int, input().split()))
    tmpCost = cost[0] / cost[1] * 1000
    if minCost > tmpCost:
        minCost = tmpCost
print("{:0.2f}".format(minCost))
