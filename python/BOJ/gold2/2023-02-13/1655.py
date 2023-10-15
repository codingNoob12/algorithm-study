import heapq as hq
import sys

input = sys.stdin.readline
smalls = []
larges = []
middle = None
for i in range(int(input().rstrip())):
    num = int(input().rstrip())
    if middle is None:
        middle = num
        hq.heappush(smalls, -num)
    elif middle < num:
        hq.heappush(larges, num)
    else:
        hq.heappush(smalls, -num)

    if len(larges) > len(smalls):
        hq.heappush(smalls, -hq.heappop(larges))
    elif len(larges) < len(smalls) - 1:
        hq.heappush(larges, -hq.heappop(smalls))
    middle = -smalls[0]
    print(middle)
