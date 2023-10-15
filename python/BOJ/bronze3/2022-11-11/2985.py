a, b, c = map(int, input().split())
op1, op2 = '', ''
if c == a + b:
    op1, op2 = '+', '='
elif c == a - b:
    op1, op2 = '-', '='
elif c == a * b:
    op1, op2 = '*', '='
elif c == a / b:
    op1, op2 = '/', '='
elif a == b + c:
    op2, op1 = '+', '='
elif a == b - c:
    op2, op1 = '-', '='
elif a == b * c:
    op2, op1 = '*', '='
else:
    op2, op1 = '/', '='
print('{}{}{}{}{}'.format(a, op1, b, op2, c))
