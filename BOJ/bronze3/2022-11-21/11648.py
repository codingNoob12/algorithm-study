st = input()
cnt = 0
while len(st) > 1:
    tmp = 1
    for ch in st:
        tmp *= int(ch)
    st = str(tmp)
    cnt += 1
print(cnt)
