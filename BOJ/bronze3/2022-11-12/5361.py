priceDict = {'rifle': 350.34,
             'optical': 230.90,
             'sound': 190.55,
             'arm': 125.30,
             'leg': 180.90}
tc = int(input())
for _ in range(tc):
    totPrice = 0
    cntList = list(map(int, input().split()))
    prcKeys = list(priceDict.values())
    for i in range(len(cntList)):
        totPrice += prcKeys[i] * cntList[i]
    print('${:.2f}'.format(totPrice))
