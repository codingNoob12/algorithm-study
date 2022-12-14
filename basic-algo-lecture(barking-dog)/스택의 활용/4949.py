import sys
for line in sys.stdin.readlines()[:-1]:
    stk = []
    for ch in line.strip():
        if ch in '({[':
            stk.append(ch)
        elif ch in ')}]':
            if stk:
                if ch == ')' and stk.pop() == '(':
                    pass
                elif ch == '}' and stk.pop() == '{':
                    pass
                elif ch == ']' and stk.pop() == '[':
                    pass
                else:
                    print('no')
                    break
            else:
                print('no')
                break
        else:
            pass
        # print(stk)
    else:
        if stk:
            print('no')
        else:
            print('yes')
