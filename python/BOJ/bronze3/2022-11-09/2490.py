for i in range(3):
    sumVal = sum(list(map(int, input().split())))
    if sumVal == 3:
        print("A")
    elif sumVal == 2:
        print("B")
    elif sumVal == 1:
        print("C")
    elif sumVal == 0:
        print("D")
    else:
        print("E")
