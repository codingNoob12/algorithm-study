# # sol 1) n개의 입력값에 대해서 반텀씩 쪼개가면서 ai + aj == x를 만족하는 j를 찾아나감
# ## 시간 복잡도 : O(NlogN)
# n = int(input())
# arr = list(map(int, input().split()))
# x = int(input())
# arr.sort()
# cnt = 0
# for i in range(n):
#     j = i + 1
#     pre = 0
#     states = []
#     while i < j < n and j not in states:
#         tmp = arr[i] + arr[j]
#         s, e = 0, 0
#         if tmp < x:
#             if pre == 0:
#                 pre = n
#             s, e = j + 1, pre - 1
#             if arr[i] + arr[(s + e) // 2] > x:
#                 pre = j
#         elif tmp > x:
#             if pre == 0:
#                 pre = i
#             s, e = pre + 1, j - 1
#             if arr[i] + arr[(s + e) // 2] < x:
#                 pre = j
#         else:
#             cnt += 1
#             break
#         states.append(j)
#         j = (s + e) // 2
# print(cnt)

# # sol 2)
# import sys
# n = int(sys.stdin.readline())
# s = list(map(int, sys.stdin.readline().split(" ")))
# x = int(sys.stdin.readline())
# s.sort()
#
# fp=0; ep=len(s)-1; ans = 0
# while fp != ep:
#     if s[fp] + s[ep] == x:
#         ep -= 1
#         ans += 1
#     else:
#         if s[fp] + s[ep] < x:
#             fp += 1
#         else:
#             ep -= 1
# print(ans)

# sol 3)
n = int(input())
arr = list(map(int, input().split()))
x = int(input())
arr.sort()
i, j = 0, n - 1
cnt = 0
while i < j:
    tmp = arr[i] + arr[j]
    if tmp == x:
        cnt += 1
        # j -= 1
        i += 1
    elif tmp < x:
        i += 1
    else:
        j -= 1
print(cnt)
