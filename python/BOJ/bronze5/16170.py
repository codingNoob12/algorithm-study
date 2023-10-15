import datetime

dateList = datetime.datetime.now().__str__().split()[0].split("-")
for date in dateList:
    print(date)
