def invalid_case_print():
    print(0)
    exit(0)

seq = input()
stk = []

for ch in seq:
    score = 0
    if ch in ('(', '['):
        stk.append(ch)
    else:
        while stk and isinstance(stk[-1], int):
            score += stk.pop()
        if not stk:
            invalid_case_print()
        openPair = stk.pop()
        if openPair == '(' and ch == ')':
            if score != 0:
                score *= 2
            else:
                score = 2
        elif openPair == '[' and ch == ']':
            if score != 0:
                score *= 3
            else:
                score = 3
        else:
            invalid_case_print()
        stk.append(score)
if len(list(filter(lambda x: not isinstance(x, int), stk))) != 0:
    invalid_case_print()
print(sum(stk))
