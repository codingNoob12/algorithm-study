while True:
    st = input()
    if st == '0':
        break
    while len(st) >= 2:
        res = 0
        for ch in st:
            res += int(ch)
        st = str(res)
    print(st)
