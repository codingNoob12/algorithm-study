import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
ans = 0
stk = [] # e: (height, count)
for i in range(n):
    h = int(input())
    count = 1

    while stk and stk[-1][0] <= h:
        ans += stk[-1][1]
        if stk[-1][0] == h:
            count += stk[-1][1]
        stk.pop()

    if stk:
        ans += 1

    stk.append((h, count))

print(ans)
