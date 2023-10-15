def conversion(st):
    res = []
    for ch in st:
        if ord(ch) <= ord('C'):
            ch = chr(ord(ch) + 23)
        else:
            ch = chr(ord(ch) - 3)
        res.append(ch)
    return ''.join(res)

print(conversion(input()))
