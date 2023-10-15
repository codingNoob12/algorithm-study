import sys
input = sys.stdin.readline
stk = []
for _ in range(int(input())):
    line = input().strip().split()
    if line[0] == 'push':
        stk.append(int(line[1]))
    elif line[0] == 'pop':
        if stk:
            print(stk.pop())
        else:
            print(-1)
    elif line[0] == 'size':
        print(len(stk))
    elif line[0] == 'empty':
        print(0 if stk else 1)
    else:
        print(stk[-1] if stk else -1)
