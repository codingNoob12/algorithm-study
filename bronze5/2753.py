year = int(input())
isLeapYear = 0
if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
    isLeapYear = 1
print(isLeapYear)
