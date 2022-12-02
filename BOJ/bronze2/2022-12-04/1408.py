def getSeconds(time:list):
    return time[0] * 3600 + time[1] * 60 + time[2]

currentTime = list(map(int, input().split(':')))
endTime = list(map(int, input().split(':')))
currentSec = getSeconds(currentTime)
endSec = getSeconds(endTime)
leftSec = endSec - currentSec
if leftSec < 0:
    leftSec += 24 * 3600
print(f'{leftSec // 3600:02}:{leftSec // 60 % 60:02}:{leftSec % 60:02}')
