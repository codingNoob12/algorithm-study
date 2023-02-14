from datetime import date
BIRTHDAYS = {}
oldest, youngest = None, None
for _ in range(int(input())):
    name, day, month, year = input().split()
    birthDay = date(year=int(year), month=int(month), day=int(day))
    BIRTHDAYS[name] = birthDay
for name, birthDay in BIRTHDAYS.items():
    if not youngest:
        youngest = (name, birthDay)
    elif birthDay > youngest[1]:
        youngest = (name, birthDay)

    if not oldest:
        oldest = (name, birthDay)
    elif birthDay < oldest[1]:
        oldest = (name, birthDay)

print(youngest[0])
print(oldest[0])
