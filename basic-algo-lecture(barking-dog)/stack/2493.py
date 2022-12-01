# # sol 1) 시간 초과
# n = int(input())
# heights = list(map(int, input().split()))
# res = []
# for _ in range(n):
#     height = heights.pop()
#     for i in range(len(heights)-1, 0, -1):
#         if height < heights[i]:
#             res.append(i + 1)
#             break
#     else:
#         res.append(0)
# print(*res[::-1])

# # sol 2) 시간 초과
# n = int(input())
# heights = list(map(int, input().split()))
# L = 0 # 왼쪽 탑의 높이 중 최댓값. => 이 탑 왼쪽으로는 볼 필요 없다
# receives = [0]
# for i in range(1, n):
#     for j in range(i-1, L-1, -1):
#         if heights[i] <= heights[j]:
#             receives.append(j + 1)
#             break
#     else:
#         receives.append(0)
#         L = i
# print(*receives)

# sol 3)
n = int(input())
heights = list(map(int, input().split()))
stk, receive = [], [0] * n
for i, height in enumerate(heights):
    while stk and stk[-1][1] <= height:
        stk.pop()
    if stk:
        receive[i] = stk[-1][0]
    stk.append((i+1, height))
print(*receive)
