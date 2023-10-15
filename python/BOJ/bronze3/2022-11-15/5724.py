while True:
    n = int(input())
    if n == 0:
        break
    rect = 0
    for i in range(1, n+1):
        l = n + 1 - i
        rect += l ** 2
    print(rect)
