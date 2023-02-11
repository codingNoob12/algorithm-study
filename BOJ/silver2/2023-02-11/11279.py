import heapq as hq
import sys
input = sys.stdin.readline
mh = []
for _ in range(int(input().rstrip())):
    n = int(input().rstrip())
    if n == 0:
        print(-hq.heappop(mh) if mh else 0)
    else:
        hq.heappush(mh, -n)
