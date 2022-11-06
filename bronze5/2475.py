numList = list(map(int, input().split()))
sumVal = 0
for num in numList:
    sumVal += num ** 2
res = sumVal % 10
print(res)
