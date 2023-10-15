from datetime import datetime
now = input().split()
monthDict = {'January': 1, 'February': 2, 'March': 3, 'April': 4, 'May': 5, 'June': 6,
             'July': 7, 'August': 8, 'September': 9, 'October': 10, 'November': 11, 'December': 12}
t = list(map(int, now[3].split(':')))
now = datetime(int(now[2]), int(monthDict[now[0]]), int(now[1][:-1]), t[0], t[1])
if now.month == 1 and now.day == 1 and now.hour == 0 and now.minute == 0:
    print(0.0)
else:
    new = datetime(now.year+1, 1, 1, 0, 0)
    old = datetime(now.year, 1, 1, 0, 0)
    print((now - old).total_seconds() / (new - old).total_seconds() * 100)
