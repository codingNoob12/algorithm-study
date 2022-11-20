from datetime import timedelta
sH, sM, sS = map(int, input().split(':'))
eH, eM, eS = map(int, input().split(':'))
waitSeconds = timedelta(hours=eH - sH, minutes=eM - sM, seconds=eS - sS).seconds
if waitSeconds == 0:
    waitSeconds += 24 * 3600
print('{:02}:{:02}:{:02}'.format(waitSeconds // 3600, waitSeconds // 60 % 60, waitSeconds % 60))
