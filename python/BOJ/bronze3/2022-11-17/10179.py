t = int(input())
for _ in range(t):
    price = float(input())
    price = round(price * 0.8, 2)
    print(f'${price:.2f}')
