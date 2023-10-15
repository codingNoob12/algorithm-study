# sol 1)
# t = int(input())
# for _ in range(t):
#     s = []
#     for p in input():
#         if p == '(':
#             s.append(p)
#         elif len(s) > 0 and p == ')':
#             if s.pop() != '(':
#                 print('NO')
#                 break
#         elif len(s) == 0:
#             print('NO')
#             break
#     else:
#         if len(s) > 0:
#             print('NO')
#         else:
#             print('YES')

# sol 2)
for _ in range(int(input())):
    stk = []
    isVPS = True
    for ch in input():
        if ch == '(':
            stk.append(ch)
        else:
            if stk:
                stk.pop()
            else:
                isVPS = False
                break

    if stk:
        isVPS = False

    print('YES' if isVPS else 'NO')
