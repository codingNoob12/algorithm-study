from collections import deque
operators = deque()
operands = deque()
while True:
    ipt = input()
    if ipt == '=':
        break
    if ipt in ('+', '-', '*', '/'):
        operators.append(ipt)
    else:
        operands.append(int(ipt))
for i in range(len(operators)):
    num1 = operands.popleft()
    num2 = operands.popleft()
    op = operators.popleft()
    if op == '+':
        res = num1 + num2
    elif op == '-':
        res = num1 - num2
    elif op == '*':
        res = num1 * num2
    else:
        res = num1 // num2
    operands.appendleft(res)
print(operands.pop())
