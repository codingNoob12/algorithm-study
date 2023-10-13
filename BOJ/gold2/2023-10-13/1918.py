def getPriority(oper):
    if oper in ('+', '-'):
        return 1
    if oper in ('*', '/'):
        return 2
    return -1

expression = input()
stk = []
for ch in expression:
    if ch in ('+', '-', '*', '/', '(', ')'):
        if not stk:
            stk.append(ch)
            continue
        if ch == ')':
            while stk and stk[-1] != '(':
                print(stk.pop(), end='')
            stk.pop()
            continue
        while ch != '(' and stk and getPriority(ch) <= getPriority(stk[-1]):
            print(stk.pop(), end='')
        stk.append(ch)
    else:
        print(ch, end='')
while stk:
    print(stk.pop(), end='')
