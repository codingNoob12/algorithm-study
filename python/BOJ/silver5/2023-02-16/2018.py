# n = int(input())
# i, j, range_sum, count = 1, 1, 0, 1
# while i <= j <= n:
#     if range_sum < n:
#         range_sum += j
#         j += 1
#     elif range_sum == n:
#         count += 1
#         range_sum -= i
#         i += 1
#     else:
#         range_sum -= i
#         i += 1
# print(count)

n = int(input())
i, j, range_sum, count = 1, 1, 0, 0
while j <= n:
    range_sum += j
    j += 1

    while range_sum >= n:
        if range_sum == n:
            count += 1
        range_sum -= i
        i += 1

print(count)
