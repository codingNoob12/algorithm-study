import sys
input = sys.stdin.readline
heights, stk = [], []
for _ in range(int(input())):
    heights.append(int(input()))
for h in heights:
    while stk and stk[-1] <= h:
        stk.pop()
    stk.append(h)
print(len(stk))
