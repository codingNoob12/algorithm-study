for _ in range(int(input())):
    st, candi = input().split()
    stCntDict = {}
    candiCntDict = {}
    for ch in st:
        if ch in stCntDict.keys():
            stCntDict[ch] += 1
        else:
            stCntDict[ch] = 1
    for ch in candi:
        if ch in candiCntDict.keys():
            candiCntDict[ch] += 1
        else:
            candiCntDict[ch] = 1
    if stCntDict == candiCntDict:
        print('Possible')
    else:
        print('Impossible')
