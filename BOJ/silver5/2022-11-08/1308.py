import datetime

today = datetime.date(*list(map(int, input().split())))
end = datetime.date(*list(map(int, input().split())))
chk = 0
for i in range(today.year, today.year + 1000):
    if (i % 4 == 0 and i % 100 != 0) or i % 400 == 0:
        chk += 366
    else:
        chk += 365
dDay = (end - today).days
if dDay >= chk:
    print("gg")
else:
    print("D-" + str(dDay))
