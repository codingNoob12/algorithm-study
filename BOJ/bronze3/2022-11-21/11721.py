st = input()
cnt = 0
for ch in st:
    print(ch, end='')
    cnt += 1
    if cnt % 10 == 0:
        print()
