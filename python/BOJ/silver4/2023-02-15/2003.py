# sol 1) Python : 시간 초과, PyPy3 : 340ms
# n, m = map(int, input().split())
# nums = list(map(int, input().split()))
# prefix_sum = [0] * (n + 1)
#
# for i in range(1, n + 1):
#     prefix_sum[i] += prefix_sum[i - 1] + nums[i - 1]
#
# cnt = 0
# for i in range(1, n + 1):
#     for j in range(i, n + 1):
#         s, e = i - 1, j
#         if prefix_sum[e] - prefix_sum[s] == m:
#             cnt += 1
#         elif prefix_sum[e] - prefix_sum[s] > m:
#             break
# print(cnt)


# sol 2)
# n, m = map(int, input().split())
# nums = list(map(int, input().split()))
# prefix_sum = [0] * (n + 1)
#
# for i in range(1, n + 1):
#     prefix_sum[i] += prefix_sum[i - 1] + nums[i - 1]
#
# cnt = 0
# i, j = 0, 1
# while i <= j < len(prefix_sum):
#     if prefix_sum[j] - prefix_sum[i] == m:
#         cnt += 1
#         i += 1
#     elif prefix_sum[j] - prefix_sum[i] > m:
#         i += 1
#     else:
#         j += 1
# print(cnt)

# sol 3)
n, m = map(int, input().split())
nums = list(map(int, input().split()))
i, j, cnt = 0, 0, 0
sequenceSum = nums[0]
while True:
    if sequenceSum == m:
        sequenceSum -= nums[i]
        i += 1
        cnt += 1
    elif sequenceSum > m:
        sequenceSum -= nums[i]
        i += 1
    else:
        j += 1
        if j >= n:
            break
        sequenceSum += nums[j]
print(cnt)
