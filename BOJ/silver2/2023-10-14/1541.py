def calc(expression):
    nums = expression.split('+')
    res = 0
    for num in nums:
        res += int(num)
    return res

expression = input()
nums, opts = [], []

sub_expressions = expression.split('-')
res = calc(sub_expressions[0])
for sub_expression in sub_expressions[1:]:
    res -= calc(sub_expression)
print(res)
