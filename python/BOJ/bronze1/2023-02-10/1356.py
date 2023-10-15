n = input()
for seperator in range(1, len(n)):
    fore = n[:seperator]
    back = n[seperator:]
    foreMul, backMul = 1, 1
    for item in fore:
        foreMul *= int(item)
    for item in back:
        backMul *= int(item)
    if foreMul == backMul:
        print('YES')
        break
else:
    print('NO')
