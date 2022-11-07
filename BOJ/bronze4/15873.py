st = input()
sumVal = 0
if len(st) == 2:
    for ch in st:
        sumVal += int(ch)
elif st[1] == "0":
    sumVal = int(st[:2]) + int(st[2:])
else:
    sumVal = int(st[0]) + int(st[1:])
print(sumVal)
