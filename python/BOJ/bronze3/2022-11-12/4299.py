sumVal, subVal = map(int, input().split())
if (sumVal + subVal) % 2 != 0 or subVal > sumVal:
    print(-1)
else:
    dons = (sumVal + subVal) // 2
    wimbledon = sumVal - dons
    print(dons, wimbledon)
