chkList = 'LOVE'
yeonduName = input()
candidatesOfTeamName = sorted([input() for _ in range(int(input()))])
winRateDict = {}
for candidate in candidatesOfTeamName:
    countDict = {}
    for chk in chkList:
        cnt = yeonduName.count(chk) + candidate.count(chk)
        countDict[chk] = cnt
    L, O, V, E = countDict.values()
    winRate = ((L+O) * (L+V) * (L+E) * (O+V) * (O+E) * (V+E)) % 100
    winRateDict[candidate] = winRate
maxWinRate = max(winRateDict.values())
for candidate, winRate in winRateDict.items():
    if winRate == maxWinRate:
        print(candidate)
        break
