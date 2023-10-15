n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
print(*sorted(A + B))

# n, m = map(int, input().split())
# A = list(map(int, input().split()))
# B = list(map(int, input().split()))
# COUNTING_ARR = {}
# for item in A + B:
#     if item not in COUNTING_ARR:
#         COUNTING_ARR[item] = 1
#     else:
#         COUNTING_ARR[item] += 1
# for item in sorted(COUNTING_ARR.keys()):
#     for _ in range(COUNTING_ARR[item]):
#         print(item, end=' ')
