# 1 + 6 * a * (a + 1) / 2 >= n > 1 + 6 * (a - 1) * a / 2
# 1 + 3 * a * (a + 1) >= n > 1 + 3 * (a - 1) * a
# 3 * a * (a + 1) >= n-1 > 3 * (a - 1) * a
# 3 * a ** 2 + 3 * a - n + 1 >= 0
n = int(input())
sumVal = 0
for i in range(n):
    sumVal += i
    if sumVal > (n - 2) / 6:
        print(i + 1)
        break
