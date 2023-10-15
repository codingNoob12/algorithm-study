stk = []
ans = 0
st = input()
for i, ch in enumerate(st):
    if ch == '(' and st[i + 1] == ')':
        ans += len(stk)
    elif ch == ')' and st[i - 1] == '(':
        continue
    elif ch == '(':
        stk.append(ch)
    else:
        stk.pop()
        ans += 1
print(ans)
