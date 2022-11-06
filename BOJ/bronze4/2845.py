l, p = map(int, input().split())
numList = list(map(int, input().split()))
pop = l * p
for num in numList:
    print(num - pop, end=" ")
