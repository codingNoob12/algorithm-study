from datetime import timedelta
now = list(map(int, input().split(":")))
throw = list(map(int, input().split(':')))
now = timedelta(hours=now[0], minutes=now[1], seconds=now[2])
throw = timedelta(hours=throw[0], minutes=throw[1], seconds=throw[2])
wait = throw - now
if wait.seconds != 0:
    print('{:02}:{:02}:{:02}'.format(wait.seconds // 3600, wait.seconds // 60 % 60, wait.seconds % 60))
else:
    print('24:00:00')
