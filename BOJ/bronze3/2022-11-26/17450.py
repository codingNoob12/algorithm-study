snacks = ['S', 'N', 'U']
minPerformancePerPrice = 0
minSnack = None
for snack in snacks:
    price, weight = map(int, input().split())
    toPay = price * 10 if price * 10 < 5000 else price * 10 - 500
    performancePerPrice = (10 * weight) / toPay
    if minPerformancePerPrice < performancePerPrice:
        minPerformancePerPrice = performancePerPrice
        minSnack = snack
print(minSnack)
