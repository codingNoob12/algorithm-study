import sys
input = sys.stdin.readline
stk, x = [], 1
n = int(input())
log = []
for i in range(1, n+1):
    num = int(input())
    while num >= x and x <= n:
        stk.append(x)
        log.append('+')
        x += 1
    if num == stk[-1]:
        stk.pop()
        log.append('-')
if stk:
    print('NO')
else:
    print(*log, sep='\n')
