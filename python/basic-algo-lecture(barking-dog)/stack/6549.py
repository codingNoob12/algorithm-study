import sys

def input():
    return sys.stdin.readline().rstrip()

while True:
    n, *heights = map(int, input().split())

    if n == 0:
        break

    ans = 0
    stk = [] # e: (index, height)
    for i, h in enumerate(heights):
        idx = i
        while stk and stk[-1][1] >= h:
            ans = max(ans, (i - stk[-1][0]) * stk[-1][1])
            idx = stk[-1][0]
            stk.pop()

        stk.append((idx, h))

    while stk:
        i, h = stk.pop()
        ans = max(ans, (n - i) * h)

    print(ans)
