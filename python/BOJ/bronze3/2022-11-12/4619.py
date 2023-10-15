import math
while True:
    b, n = map(int, input().split())
    if b == 0 and n == 0:
        break
    if n == 1:
        print(b)
        continue
    a = 0
    for i in range(1, int(math.sqrt(b))+1):
        a = i if abs(b - a ** n) > abs(b - i ** n) else a
    print(a)
