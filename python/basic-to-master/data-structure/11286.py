# # sol 1)
# import heapq as hq
# import sys
# h = []
# for _ in range(int(input())):
#     x = int(sys.stdin.readline())
#     if x != 0:
#         hq.heappush(h, (abs(x), x))
#     elif len(h) > 0:
#         print(h[0][1])
#         hq.heappop(h)
#     else:
#         print(0)

# # sol 2)
# import heapq as hq
# import sys
#
# input = sys.stdin.readline
# pq = []
# for _ in range(int(input())):
#     x = int(input())
#     if x != 0:
#         hq.heappush(pq, (abs(x), x))
#     else:
#         print(hq.heappop(pq)[1] if pq else 0)

# sol 3)
# 양수는 수가 클수록 절댓값이 크다, 음수는 수가 작을수록 절댓값이 크다.
# 양수는 최소힙, 음수는 최대힙으로 관리
# python에서는 기본적으로 최소힙으로 관리 => 최대힙으로 사용하고 싶으면 부호를 바꿔서 넣고 뺄 때, 다시 부호를 바꿔주
import heapq as hq
import sys

input = sys.stdin.readline
min_heap = []  # 양수
max_heap = []  # 음수
for _ in range(int(input())):
    x = int(input())
    if x != 0:
        if x > 0:
            hq.heappush(min_heap, x)
        else:
            hq.heappush(max_heap, -x)
    else:
        if min_heap:
            if max_heap:
                if min_heap[0] < max_heap[0]:
                    print(hq.heappop(min_heap))
                else:
                    print(-hq.heappop(max_heap))
            else:
                print(hq.heappop(min_heap))
        else:
            if max_heap:
                print(-hq.heappop(max_heap))
            else:
                print(0)
