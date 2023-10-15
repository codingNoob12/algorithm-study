t = int(input())
for _ in range(t):
    numList = list(map(int, input().split()))
    evenList = []
    for num in numList:
        if num % 2 == 0:
            evenList.append(num)
    print(sum(evenList), min(evenList))
