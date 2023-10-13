def printStak(stk: list):
    while stk:
        print(stk.pop(), end='')

S = input()
stk = []
tag = False
for i, ch in enumerate(S):
    if ch == '<':
        tag = True
        printStak(stk)
        print(ch, end='')
    elif ch == '>':
        tag = False
        print(ch, end='')
    elif tag:
        print(ch, end='')
    elif ch == ' ':
        printStak(stk)
        print(ch, end='')
    else:
        stk.append(ch)
printStak(stk)
