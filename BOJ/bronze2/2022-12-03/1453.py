n = int(input())
prefers = list(map(int, input().split()))
occupiedSeats = []
declinedCnt = 0
for prefer in prefers:
    if prefer not in occupiedSeats:
        occupiedSeats.append(prefer)
    else:
        declinedCnt += 1
print(declinedCnt)
