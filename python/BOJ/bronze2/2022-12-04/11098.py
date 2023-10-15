for _ in range(int(input())):
    playerDict = {}
    for _ in range(int(input())):
        cost, name = input().split()
        playerDict[name] = int(cost)
    maxCost = max(playerDict.values())
    for name, cost in playerDict.items():
        if cost == maxCost:
            print(name)
            break
