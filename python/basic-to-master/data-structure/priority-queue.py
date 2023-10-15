# Priority Queue <= heap
# Min-Heap in Python, Max-Heap in C++
# 완전 이진 트리 & pop하면 root를 pop
import heapq as hq

pq = []
hq.heappush(pq, 456)
hq.heappush(pq, 123)
hq.heappush(pq, 789)
print('size:', len(pq))
while len(pq) > 0:
    # print(heapq.heappop(pq))
    print(pq[0])
    hq.heappop(pq)

# 2
# thread-safe. Queue와 deque의 관계와 비슷
# 그래서 heapq를 더 많이 사용
from queue import PriorityQueue

pq = PriorityQueue()
pq.put(6)
pq.put(10)
pq.put(-5)
pq.put(0)
pq.put(8)
while not pq.empty():
    print(pq.get())
