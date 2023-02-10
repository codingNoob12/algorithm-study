scenarioNo = 0
while True:
    scenarioNo += 1
    n = int(input())
    if n == 0:
        break
    nameList = [input() for _ in range(n)]
    seizureDict = {}
    for _ in range(2 * n - 1):
        key, value = input().split()
        if key not in seizureDict.keys():
            seizureDict[key] = value
        else:
            seizureDict.pop(key)
    for key in seizureDict.keys():
        print(scenarioNo, nameList[int(key) - 1])
