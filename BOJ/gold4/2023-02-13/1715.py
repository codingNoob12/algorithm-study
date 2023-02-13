# import sys
# input = sys.stdin.readline
# cardDecks = sorted([int(input().rstrip()) for _ in range(int(input().rstrip()))])
# cnt = 0
# tmpList = [sum(cardDecks[:i+1]) for i in range(1, len(cardDecks))]
# print(sum(tmpList))

import sys
import heapq as hq
input = sys.stdin.readline
cards = []
for _ in range(int(input().rstrip())):
    hq.heappush(cards, int(input().rstrip()))
cnt = 0
while len(cards) != 1:
    a = hq.heappop(cards)
    b = hq.heappop(cards)
    hq.heappush(cards, a + b)
    cnt += a + b
print(cnt)
