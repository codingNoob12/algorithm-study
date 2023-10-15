# sol 1)
# VOTE_COUNT = {i: int(input()) for i in range(1, int(input()) + 1)}
# cnt = 0
# while True:
#     maxCandidate = max(VOTE_COUNT, key=VOTE_COUNT.get)
#     if maxCandidate == 1:
#         if list(VOTE_COUNT.values()).count(VOTE_COUNT[maxCandidate]) != 1:
#             cnt += 1
#         break
#     VOTE_COUNT[maxCandidate] -= 1
#     VOTE_COUNT[1] += 1
#     cnt += 1
# print(cnt)

# sol 2)
import heapq as hq

pq = [[-int(input()), i] for i in range(1, int(input()) + 1)]
dasom = pq.pop(0)[0]
hq.heapify(pq)
cnt = 0
while pq:
    vote, candidate = hq.heappop(pq)
    if -dasom > -vote:
        break
    vote += 1
    dasom -= 1
    hq.heappush(pq, [vote, candidate])
    cnt += 1
print(cnt)
