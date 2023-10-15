# S = int(input())
# ans = set()
# remain, i = S, 1
# while remain > 0:
#     if remain < i:
#         largest = max(ans)
#         ans.remove(largest)
#         remain += largest
#         continue
#     ans.add(i)
#     remain -= i
#     i += 1
# print(len(ans))

S = int(input())
rangeSum, i = 0, 0
while S > rangeSum:
    rangeSum = i * (i + 1) // 2
    i += 1
candidates = list(range(1, i))
if sum(candidates) != S:
    candidates.remove(rangeSum - S)
print(len(candidates))
