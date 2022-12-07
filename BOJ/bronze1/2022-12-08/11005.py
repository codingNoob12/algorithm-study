def notation(x, no):
    res = []
    while x:
        tmp = x % no if x % no < 10 else chr(x % no + 55)
        res.insert(0, tmp)
        x //= no
    return res

n, b = map(int, input().split())
print(*notation(n, b), sep='')
