import calendar
x, y = map(int, input().split())
dayOfWeek = calendar.weekday(year=2007, month=x, day=y)
if dayOfWeek == 0:
    print('MON')
elif dayOfWeek == 1:
    print('TUE')
elif dayOfWeek == 2:
    print('WED')
elif dayOfWeek == 3:
    print('THU')
elif dayOfWeek == 4:
    print('FRI')
elif dayOfWeek == 5:
    print('SAT')
else:
    print('SUN')
