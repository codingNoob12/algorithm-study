# n, m = map(int, input().split())
# for i in range(n):
#     print(m * i + 1, end='')
#     for j in range(2, m+1):
#         print('', m * i + j, end='')
#     print()

n, m = map(int, input().split())
nums = [[m * i + j for j in range(1, m+1)] for i in range(n)]
for line in nums:
    print(*line)

# comprehension이 코드도 짧고 속도도 더 빠르다.
