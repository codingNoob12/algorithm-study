buggerPriceList = []
drinkPriceList = []
for _ in range(3):
    buggerPriceList.append(int(input()))
for _ in range(2):
    drinkPriceList.append(int(input()))
cheapestSet = min(buggerPriceList) + min(drinkPriceList) - 50
print(cheapestSet)
