e, m, c = map(int, input().split())
tmp, res = e + m, 0
while tmp >= c:
    change = tmp // c
    res += change
    tmp %= c
    tmp += change
print(res)
