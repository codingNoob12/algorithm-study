import heapq as hq
import sys
input = sys.stdin.readline
heap = []
for _ in range(int(input().rstrip())):
    n = int(input().rstrip())
    if n == 0:
        print(hq.heappop(heap) if heap else 0)
    else:
        hq.heappush(heap, n)
