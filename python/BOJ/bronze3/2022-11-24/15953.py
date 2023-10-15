t = int(input())
price1List = [5_000_000, 3_000_000, 2_000_000, 500_000, 300_000, 100_000]
price2List = [5_120_000, 2_560_000, 1_280_000, 640_000, 320_000]
for _ in range(t):
    a, b = map(int, input().split())
    place1, place2 = 0, 0
    if a != 0:
        for i in range(1, 7):
            if a <= i * (i + 1) // 2:
                place1 = i
                break
    if b != 0:
        for i in range(5):
            b = b >> 1
            if b == 0:
                place2 = i + 1
                break
    price = 0
    if place1 != 0 and place1 <= 6:
        price += price1List[place1-1]
    if place2 != 0 and place2 <= 5:
        price += price2List[place2-1]
    print(price)
