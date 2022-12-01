import sys
input = sys.stdin.readline
for _ in range(int(input())):
    expression = input().strip().split()
    operand = float(expression.pop(0))
    for operator in expression:
        if operator == '@':
            operand *= 3
        elif operator == '%':
            operand += 5
        else:
            operand -= 7
    print(f'{operand:.2f}')
