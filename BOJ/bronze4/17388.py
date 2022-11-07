rateList = list(map(int, input().split()))
minRate = rateList.index(min(rateList))
if sum(rateList) >= 100:
    print("OK")
elif minRate == 0:
    print("Soongsil")
elif minRate == 1:
    print("Korea")
else:
    print("Hanyang")
