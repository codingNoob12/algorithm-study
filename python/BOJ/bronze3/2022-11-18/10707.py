xUnit = int(input())
yDefault = int(input())
yLimit = int(input())
yExtraUnit = int(input())
p = int(input())
xCost, yCost = p * xUnit, yDefault
if yLimit < p:
    yCost += (p - yLimit) * yExtraUnit
cost = xCost if xCost < yCost else yCost
print(cost)
