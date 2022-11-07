n = int(input())
p = int(input())
idx = n // 5 if n // 5 <= 5 else 5
payList = [p, p - 500, int(p * 0.9), p - 2000, int(p * 0.75)]
pay = min(payList[:idx + 1])
if pay < 0:
    pay = 0
print(pay)
