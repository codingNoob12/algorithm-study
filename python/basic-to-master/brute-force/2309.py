# sol 1)
# from itertools import combinations
# heights = [int(input()) for _ in range(9)]
# for candidate in combinations(heights, 7):
#     if sum(candidate) == 100:
#         print(*sorted(candidate), sep='\n')
#         break

# sol 2)
# heights = [int(input()) for _ in range(9)]
# res = []
# for i in range(9):
#     for j in range(i+1, 9):
#         if sum(heights) - (heights[i] + heights[j]) == 100:
#             for k in range(9):
#                 if k in (i, j):
#                     continue
#                 res.append(heights[k])
#             res.sort()
#             print(*res, sep='\n')
#             exit(0)

# sol 3)
heights = [int(input()) for _ in range(9)]
heights.sort()
tot = sum(heights)


def f():
    for i in range(9):
        for j in range(i+1, 9):
            if tot - (heights[i] + heights[j]) == 100:
                for k in range(9):
                    if k not in (i, j):
                        print(heights[k])
                return


f()
