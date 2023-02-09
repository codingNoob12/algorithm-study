for _ in range(int(input())):
    n = int(input())
    posList = list(map(int, input().split()))
    dist = max(posList) - min(posList)
    print(2 * dist)
