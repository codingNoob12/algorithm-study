import sys
PI, cnt = 3.1415927, 1
lines = sys.stdin.readlines()
for line in lines:
    diameter, cycle, time = map(float, line.strip().split())
    if cycle == 0:
        continue
    dist = diameter / 5280 / 12 * PI * cycle
    velo = dist / time * 3600
    print('Trip #{}: {:0.2f} {:0.2f}'.format(cnt, dist, velo))
    cnt += 1
