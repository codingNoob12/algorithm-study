def trophies(heights: list):
    stk = [heights[0]]
    for height in heights:
        if stk and stk[-1] < height:
            stk.append(height)
    return len(stk)

heights = [int(input()) for _ in range(int(input()))]
print(trophies(heights))
print(trophies(heights[::-1]))
