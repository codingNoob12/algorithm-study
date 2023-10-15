cowLocations = {}
cnt = 0
for _ in range(int(input())):
    cowNumber, cowLocation = map(int, input().split())
    if cowNumber in cowLocations.keys():
        if cowLocations[cowNumber] != cowLocation:
            cnt += 1
            cowLocations[cowNumber] = cowLocation
    else:
        cowLocations[cowNumber] = cowLocation
print(cnt)
