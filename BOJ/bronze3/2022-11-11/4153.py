from math import sqrt
while True:
    numList = list(map(int, input().split()))
    numList.sort()
    a, b, c = numList
    if a == b == c == 0:
        break
    if c == sqrt(a ** 2 + b ** 2):
        print('right')
    else:
        print('wrong')
