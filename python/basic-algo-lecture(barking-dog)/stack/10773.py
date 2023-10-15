import sys
input = sys.stdin.readline
stk = []
for _ in range(int(input())):
    num = int(input())
    if num:
        stk.append(num)
    else:
        stk.pop()
print(sum(stk))
