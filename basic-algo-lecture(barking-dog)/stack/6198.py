# # sol 1)
# import sys
# input = sys.stdin.readline
# n = int(input())
# heights = [int(input()) for _ in range(n)]
# cnt = [0] * n
# stk = [] # 오른쪽 limit를 저장, 높이가 달라지면 update... 작으면 스택 마지막에서 왼쪽으로 찾아서 append, 크다면 pop하고 다시 찾기
# for i, height in enumerate(heights):
#     s = i + 1
#     while stk and stk[0][0] <= i:
#         s = stk.pop(0)
#     if stk:
#         if stk[-1][1] > height:
#             tmp = stk[-1][0]
#             s = stk.pop()[1]
#         if stk and stk[-1][1] < height:
#             s = stk[-1][0]
#     for idx in range(i, n):
#         if height < heights[idx]:
#             stk.append((idx, heights[idx]))
#             break
#     if stk:
#         cnt[i] = stk[-1][0] - i - 1
#     else:
#         cnt[i] = n - i - 1
# print(sum(cnt))

# # sol 2)
# import sys
# input = sys.stdin.readline
# buildings = [int(input()) for i in range(int(input()))]
# stack = []
# result = 0
# for b in buildings:
#     while stack and stack[-1] <= b:
#         stack.pop()
#     stack.append(b)
#     result += len(stack) - 1
#
# print(result)

# review
# # 건물 기준으로 세는 것 => 기준이 불명확해서 시간 복잡도 N**2나옴
# # 그래서, 옥상에서 체크 가능한 것들을 리스트로 관리 & 갯수 세서 더해주면 루프 한 번만에 구할 수 있다.
import sys
input = sys.stdin.readline
heights = [int(input()) for i in range(int(input()))]
stk, res = [], 0
for height in heights:
    while stk and stk[-1] <= height:
        stk.pop()
    stk.append(height)
    res += len(stk) - 1
print(res)
