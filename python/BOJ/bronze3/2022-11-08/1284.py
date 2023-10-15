while True:
    num = input()
    if num == "0":
        break
    width = len(num) + 1
    for ch in num:
        if ch == "1":
            width += 2
        elif ch == "0":
            width += 4
        else:
            width += 3
    print(width)
