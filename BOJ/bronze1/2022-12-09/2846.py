n = int(input())
heights = list(map(int, input().split()))
slopes = [0] * n
for i in range(n - 1):
    if heights[i] < heights[i + 1]:
        slopes[i] = 1
    elif heights[i] > heights[i + 1]:
        slopes[i] = -1
maxHeight, flag = 0, True
s, e = 0, 0
for i, slope in enumerate(slopes):
    if slope == 1:
        if flag is True:
            s = i
        flag = False
    else:
        flag = True
        e = i
    if flag:
        diff = heights[e] - heights[s]
        maxHeight = diff if diff > maxHeight else maxHeight
else:
    if flag:
        diff = heights[e] - heights[s]
        maxHeight = diff if diff > maxHeight else maxHeight
print(maxHeight)
