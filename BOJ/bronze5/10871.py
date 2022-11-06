n, x = map(int, input().split())
numList = list(map(int, input().split()))
for num in numList:
    if num < x:
        print(num, end=' ')
