import sys

N, M, B = map(int, input().split())
site = [list(map(int, input().split())) for _ in range(N)]
minT, maxH = sys.maxsize, sys.maxsize
for h in range(257):
    block, T = B, 0
    for i in range(N):
        for j in range(M):
            diff = site[i][j] - h

            if diff == 0:
                continue

            if diff > 0:
                T += 2 * abs(diff)
                block += abs(diff)
            else:
                T += abs(diff)
                block -= abs(diff)

    if block >= 0 and T <= minT:
        minT = T
        maxH = h
print(minT, maxH)
